#include "inc/incense_vec.h"
#include "inc/match_core.h"
#include "inc/filter_rule.h"
#include "data/product_data.h"

int main(void)
{
    // 构造用户需求示例：湿热体质、卧室助眠、夏季
    UserDemand user = {
        .body = BODY_HOT,
        .scene = SCENE_SLEEP,
        .now_sea = SEA_SUMMER,
        .ban_cnt = 0
    };
    // 用户偏好向量：药香、安神、润肺
    user.demand_vec = (IncenseVec){
        .wood=3, .flower=2, .herb=8, .cool=4, .sweet=2,
        .calm=9, .refresh=1, .damp=5, .lung=7,
        {0,1,1,0}, 0, 0
    };

    printf("===== 香品智能匹配系统 =====\n");
    printf("用户需求向量：\n");
    print_vec(user.demand_vec);

    // 加载成品库
    int prod_cnt = sizeof(g_product_list)/sizeof(IncenseProduct);
    IncenseProduct candidate[32];
    int cand_cnt = 0;

    // 第一层硬过滤
    for(int i=0; i<prod_cnt; i++)
    {
        if(filter_all_rule(user, g_product_list[i]) == 0)
        {
            candidate[cand_cnt++] = g_product_list[i];
        }
    }
    printf("过滤后候选数量：%d\n", cand_cnt);

    // 按匹配分排序
    sort_product_score(candidate, cand_cnt, user);

    // 输出Top5推荐
    printf("\n===== 推荐香品Top5 =====\n");
    int show = cand_cnt>5 ? 5 : cand_cnt;
    for(int i=0; i<show; i++)
    {
        float s = calc_total_score(user, candidate[i], 0);
        printf("%d. %s 匹配分：%.2f\n", i+1, candidate[i].name, s);
        print_vec(candidate[i].vec);
    }

    return 0;
}