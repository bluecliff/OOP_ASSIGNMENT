/**
 * @file CFloor.h
 * @brief	声明楼层类CFloor
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-17
 */

#ifndef CFLOOR_H_
#define CFLOOR_H_

#include "CPasseng.h"
#include "CBuilding.h"
#include <list>

class CFloor
{
	public:
		/**
		 * @brief	构造函数
		 *
		 * @param	parent	初始化该电梯所属的建筑
		 */
		CFloor(CBuilding* parent):parent(parent);
		~CFloor();
		/**
		 * @brief	实例数目
		 */
		static int count;
		/**
		 * @brief	离开等待队列
		 *
		 * @param	i	离开的乘客的ID
		 */
		void outWaitingList(int i);
		/**
		 * @brief	进入停留队列
		 *
		 * @param	i	要进入停留队列的乘客ID
		 */
		void inStayingList(int i);
		/**
		 * @brief	更新停留队列和等待队列，即把停留时间超过最大停留时间的人从停留队列转入等待队列
		 */
		void updatePassengeList();
		/**
		 * @brief	返回waitingList的大小，即在等待电梯的人的数目
		 *
		 * @return	
		 */
		int getWaitListSize();
		/**
		 * @brief	返回停留队列的人的数目
		 *
		 * @return	
		 */
		int getStayingListSize();
	private:
		/**
		 * @brief	该层的ID
		 */
		int id;
		/**
		 * @brief	楼层所属的建筑
		 */
		CBuilding* parent;
		/**
		 * @brief	该层的正在等待电梯的乘客id队列
		 */
		list<int> waitingList;
		/**
		 * @brief	停留在该层的乘客id队列
		 */
		list<int> stayingList;
};


#endif
