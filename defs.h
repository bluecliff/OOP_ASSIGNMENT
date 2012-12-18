/**
 * @file defs.h
 * @brief	基本的仿真参数的全局定义
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-13
 */

#ifndef DEFS_H_
#define DEFS_H_

/**
 * @brief	最大人数
 */
const int passenger_max=1000;
/**
 * @brief	乘客在某一楼层停留的最大时间
 */
int passenger_remain_max=120;
/**
 * @brief	乘客在某一楼层停留的最小时间
 */
int passenger_remain_min=10;
/**
 * @brief	开放时间，即产生乘客的时间,分钟
 */
int opening_time=1;

/**
 * @brief	电梯运行速度秒每层
 */
int elevator_speed_running=1;
/**
 * @brief	电梯上下人的速度
 */
int elevator_speed_outin=1;
/**
 * @brief	电梯的最大载人数
 */
int elevator_capacity=10;
/**
 * @brief	电梯数目
 */
const int elevator_count=10;

/**
 * @brief	最大楼层
 */
#define max_floors 40
/**
 * @brief	电梯的种类
 */
#define elevator_kind_count 5
/**
 * @brief	电梯种类设置表0标识该种类电梯在该层是不可停靠的，1标识可停靠
 */
const int elevator_kind[elevator_kind_count][max_floors]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
};
#endif

