/**
 * @file CPassenger.h
 * @brief	声明乘客类
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-14
 */
#ifndef CPASSENGER_H_
#define CPASSENGER_H_

class CPassenger
{
	public:
		CPassenger();
		~CPassenger();
		/**
		 * @brief	实例个数
		 */
		static int count;
	private:
		/**
		 * @brief	该实例的标识
		 */
		int id;
		/**
		 * @brief	目标楼层
		 */
		int destination;
		/**
		 * @brief	
		 */
		int time_remaining;
		int time_to_remain;
		int count_in;
		int count_max_in;
};

#endif
