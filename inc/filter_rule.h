#ifndef FILTER_RULE_H
#define FILTER_RULE_H

#include "incense_vec.h"

// 1：需要过滤剔除 0：保留
int filter_all_rule(UserDemand user, IncenseProduct prod);

// 检查是否包含禁用原料
int has_ban_material(UserDemand user, IncenseProduct prod);

// 体质冲突判断
int body_conflict(UserDemand user, IncenseProduct prod);

// 场景冲突判断
int scene_conflict(UserDemand user, IncenseProduct prod);

#endif