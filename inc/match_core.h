#ifndef MATCH_CORE_H
#define MATCH_CORE_H

#include "incense_vec.h"

// 余弦相似度计算
float cos_similarity(IncenseVec user, IncenseVec prod);

// 综合打分：相似度+季节+配伍奖惩
float calc_total_score(UserDemand user, IncenseProduct prod, int conflict_flag);

// 香品排序（降序）
void sort_product_score(IncenseProduct list[], int num, UserDemand user);

#endif