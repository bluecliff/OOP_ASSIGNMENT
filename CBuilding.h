/**
 * @file CBuilding.h
 * @brief	主体类声明
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-17
 */
#ifndef CBUILDING_H_
#define CBUILDING_H_

#include "defs.h"
#include "CPassenger.h"
#include "CElevator.h"
#include "CFloor.h"

class CBuilding
{
	public:
		CBuilding();
		~CBuilding();
		void init();
		void destroy();
		CPassenger* getPassengerByID(int id);
		void onClick();

	private:
		/**
		 * @brief	电梯队列
		 */
		CElevator* elevators[elevator_count];
		/**
		 * @brief	用户队列
		 */
		CPassenger* passengers[passenger_max];
		/**
		 * @brief	楼层队列
		 */
		CFloor* floors[max_floors];
		/**
		 * @brief	电梯数目
		 */
	//	int elevators_num;
		/**
		 * @brief	乘客数目
		 */
	//	int passengers_num;
		/**
		 * @brief	楼层数目
		 */
	//	int floors_num;
};


#endif

