#include "inc/match_core.h"

float cos_similarity(IncenseVec u, IncenseVec p)
{
    float dot = u.wood*p.wood + u.flower*p.flower + u.herb*p.herb
              + u.cool*p.cool + u.sweet*p.sweet
              + u.calm*p.calm + u.refresh*p.refresh
              + u.damp*p.damp + u.lung*p.lung;

    float mod_u = sqrt(pow(u.wood,2)+pow(u.flower,2)+pow(u.herb,2)+pow(u.cool,2)+pow(u.sweet,2)
                      +pow(u.calm,2)+pow(u.refresh,2)+pow(u.damp,2)+pow(u.lung,2));
    float mod_p = sqrt(pow(p.wood,2)+pow(p.flower,2)+pow(p.herb,2)+pow(p.cool,2)+pow(p.sweet,2)
                      +pow(p.calm,2)+pow(p.refresh,2)+pow(p.damp,2)+pow(p.lung,2));

    if(mod_u < 0.001f || mod_p < 0.001f)
        return 0.0f;
    return dot / (mod_u * mod_p);
}

float calc_total_score(UserDemand user, IncenseProduct prod, int conflict)
{
    float sim = cos_similarity(user.demand_vec, prod.vec);
    float score = sim;

    // 时令加分
    if(prod.vec.season[user.now_sea])
        score += 0.15f;
    // 相克扣分
    if(conflict)
        score -= 0.25f;

    if(score < 0) score = 0;
    return score;
}

static void swap_prod(IncenseProduct *a, IncenseProduct *b)
{
    IncenseProduct t = *a;
    *a = *b;
    *b = t;
}

void sort_product_score(IncenseProduct list[], int num, UserDemand user)
{
    // 简易冒泡排序
    for(int i=0; i<num-1; i++)
    {
        for(int j=0; j<num-1-i; j++)
        {
            float s1 = calc_total_score(user, list[j], 0);
            float s2 = calc_total_score(user, list[j+1], 0);
            if(s1 < s2)
                swap_prod(&list[j], &list[j+1]);
        }
    }
}