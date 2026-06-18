# Incense Match Algorithm
古艺新生 - 香品智能匹配算法 C语言轻量化工程
## 项目简介
本项目基于**多维特征向量 + 余弦相似度匹配**实现合香、线香、香牌智能推荐系统，纯标准C99编写，无第三方依赖，同时支持PC端调试与嵌入式单片机移植适配。
核心能力：
1. 多层级过滤：过敏原料、体质冲突、场景冲突硬规则前置筛选
2. 向量相似度打分：气味、功效多维余弦相似度计算匹配度
3. 动态加权修正：季节时令、香材配伍相生相克奖惩计分
4. 内置香材/成品数据库，可快速扩展自定义香方
5. 配套简易遗传算法，自动生成适配用户的定制新香方
6. 完整Demo演示程序与单元测试代码

适用场景：AI香品定制APP后端、智能香氛检测仪、线上香品推荐系统。

## 目录结构

incense-match-algorithm/
├── inc/ // 头文件目录
│ ├── incense_vec.h // 向量、枚举、结构体基础定义
│ ├── filter_rule.h // 硬过滤规则接口
│ ├── match_core.h // 相似度、打分、排序核心算法
│ ├── material_relate.h// 香材相生相克配伍矩阵
│ ├── genetic_incense.h// 遗传算法定制香方
│ └── test_case.h // 单元测试用例声明
├── src/ // 算法实现源码
│ ├── incense_vec.c
│ ├── filter_rule.c
│ ├── match_core.c
│ ├── material_relate.c
│ ├── genetic_incense.c
│ └── main.c // 程序入口演示 Demo
├── data/ // 内置香材、成品数据库
│ ├── material_data.h
│ └── product_data.h
├── test/
│ └── test_main.c // 单元测试入口
├── docs/
│ └── algorithm.md // 算法原理、设计文档
├── Makefile // Linux/macOS 编译脚本
├── Makefile_win // Windows MinGW 编译脚本
├── .gitignore // Git 忽略配置
└── README.md

plaintext
## 环境依赖
- C标准：C99
- PC编译工具：GCC / MinGW / Clang
- 嵌入式适配：STM32、51等单片机（支持定点浮点裁剪优化）
- 无第三方库，仅依赖标准math、stdio、stdlib

## 编译 & 运行
### Linux / macOS
```bash
# 编译主程序
make
# 运行演示demo
./incense_match_demo

# 编译单元测试程序
make test
./test_demo

# 清理编译产物
make clean

Windows MinGW
# 编译主程序
make -f Makefile_win
incense_match_demo.exe

# 编译单元测试
make -f Makefile_win test
test_demo.exe

# 清理文件
make -f Makefile_win clean

算法流程
硬规则过滤层
自动剔除含过敏原料、体质相冲、场景冲突的香品，缩小候选集
余弦相似度计算层
将用户需求、香品统一转为多维气味 + 功效向量，计算基础匹配分数
加权修正计分层
叠加时令季节加分、经典配伍加分，扣除原料相克惩罚分
排序输出
匹配分数降序排列，输出 TopN 推荐香品
定制香方子流程
候选香品匹配度过低时，启用遗传算法自动生成全新适配香方
核心数据模型
多维特征向量：气味维度（木 / 花 / 药 / 凉 / 甜）+ 功效维度（安神 / 醒神 / 祛湿 / 润肺）
用户模型：体质、使用场景、当前季节、禁用原料黑名单、需求向量
成品香模型：香型向量、内含香材 ID、适配季节、燥热 / 过敏属性
配伍关系矩阵：记录香材相生、相克关系，用于分数奖惩
扩展与移植说明
数据库扩展：修改data/下文件即可新增香材、成品香品
嵌入式裁剪：可关闭浮点运算，替换为定点数降低算力占用
业务拓展：可对接前端 APP、香氛检测硬件、线上商城推荐接口
迭代优化：接入用户收藏、购买数据，动态更新用户需求向量
