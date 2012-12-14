/**
 * @file CElevator.h
 * @brief	电梯类的声明
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-13
 */

#ifndef CELEVATOR_H_
#define CELEVATOR_H_

#include "defs.h"
#include "CBuilding.h"
#include <list>
/**
 * @brief	电梯的状态，有挂起，等待，运行三种状态
 */
enum elevator_status {halt,waiting,running};

struct elevator_current_floor
{
	int floor;
	int time_past;
};
/**
 * @brief	声明电梯类
 */
class CElevator
{
	public:
		/**
		 * @brief	构造函数
		 *
		 * @param	kind	电梯种类
		 * @param	parent	电梯所属的建筑
		 * @param	current_floor	当前所在层
		 * @param	speed_running	运行速度
		 * @param	speed_outin	上下乘客的速度
		 * @param	capacity	电梯的载人上限
		 */
		CElevator(int kind,CBuilding* parent,int current_floor=1;int speed_running=elevator_speed_running,int speed_outin=elevator_speed_outin,int capacity=elevator_capacity):kind(kind),parent(parent),speed_running(speed_running),speed_outin(speed_outin),capacity(capacity);
		~CElevator();
		/**
		 * @brief	电梯类实例化的数量
		 */
		static int count;
		/**
		 * @brief	编号为i的人进入电梯
		 *
		 * @param	i
		 */
		bool in(int i);
		/**
		 * @brief	出一个人	
		 *
		 */
		bool out();
		/**
		 * @brief	从等待进入运行
		 */
		void run();
		/**
		 * @brief	从等待进入挂起
		 */
		void haltdown();
		/**
		 * @brief	从运行进入等待
		 */
		void stop();
		/**
		 * @brief	从挂起进入等待
		 */
		void startup();
		/**
		 * @brief	返回电梯当前的状态	
		 *
		 * @return	
		 */
		elevator_status getElevatorStatus();
		/**
		 * @brief	获取电梯当前的所在楼层
		 *
		 * @return	若处于整数楼层，则返回所在楼层,否则返回-1
		 */
		int getCurrentFloor();
		/**
		 * @brief	响应一个时钟周期，
		 */
		void onClock();
	private:
		/**
		 * @brief	电梯标识
		 */
		int id;
		/**
		 * @brief	电梯种类
		 */
		int kind;
		/**
		 * @brief	电梯当前所在楼层
		 */
		elevator_current_floor current_floor;
		/**
		 * @brief	需要停靠的楼层,需要停的为true,不需要停的为false
		 */
		bool to_floor[max_floors];
		/**
		 * @brief	电梯所属建筑
		 */
		CBuilding* parent;
		/**
		 * @brief	最大载人
		 */
		int capacity;
		/**
		 * @brief	电梯运行速度
		 */
		int speed_running;
		/**
		 * @brief	上下人速度
		 */
		int speed_outin;
		/**
		 * @brief	电梯状态
		 */
		elevator_status status;
		/**
		 * @brief	 等待或者运行状态下电梯的方向
		 */
		bool direction;
		/**
		 * @brief	乘员队列
		 */
		list<int> passengers;
};

#endif
