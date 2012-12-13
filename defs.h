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
int elevator_count=10;
#define elevator_kind_count 5
int elevator_kind[elevator_kind_count]=
{
};
#endif

