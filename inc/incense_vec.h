#ifndef INCENSE_VEC_H
#define INCENSE_VEC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 季节枚举
typedef enum {
    SEA_SPRING = 0,
    SEA_SUMMER,
    SEA_AUTUMN,
    SEA_WINTER
} SeasonType;

// 使用场景枚举
typedef enum {
    SCENE_SLEEP,    // 助眠
    SCENE_WORK,     // 办公醒神
    SCENE_ZEN,      // 禅修
    SCENE_HOME,     // 居家
    SCENE_CAR       // 车载
} SceneType;

// 体质类型
typedef enum {
    BODY_PINGHE,
    BODY_HOT,
    BODY_COLD,
    BODY_DAMP
} BodyType;

// 多维气味功效向量
typedef struct {
    // 气味维度 0~10
    float wood;
    float flower;
    float herb;
    float cool;
    float sweet;
    // 功效维度 0~10
    float calm;    // 安神
    float refresh; // 醒神
    float damp;    // 祛湿
    float lung;    // 润肺
    // 四季适配 0/1
    int season[4];
    // 燥热属性
    int hot_attr;
    // 过敏标记 1=致敏
    int allergy;
} IncenseVec;

// 成品香结构体
typedef struct {
    char name[32];
    IncenseVec vec;
    int material_id[8]; // 内含香材ID
    int mat_cnt;
} IncenseProduct;

// 用户需求结构体
typedef struct {
    IncenseVec demand_vec;
    BodyType body;
    SceneType scene;
    SeasonType now_sea;
    int ban_mat[16]; // 禁用香材黑名单
    int ban_cnt;
} UserDemand;

// 向量打印调试函数
void print_vec(IncenseVec vec);

#endif