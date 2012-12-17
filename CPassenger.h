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
		/**
		 * @brief	构造函数
		 *
		 * @param	destination	初始化目的楼层
		 * @param	time_to_remain	初始化要停留的时间
		 * @param	count_max_in	初始化需要乘坐电梯的最大次数
		 */
		CPassenger(int destination,int time_to_remain,int count_max_in):destination(destination),time_to_remain(time_to_remain,count_max_in(count_max_in));
		~CPassenger();
		/**
		 * @brief	在每次准备成电梯时初始化目的层和在目的层停留的时间
		 *
		 * @param	destination
		 * @param	time_to_remain
		 */
		void init(int destination,int time_to_remain);
		/**
		 * @brief	获取该人的目的层
		 *
		 * @return	
		 */
		int getDestination();
		/**
		 * @brief	获取该人已经停留的时间
		 *
		 * @return	
		 */
		int getTimeRemaining();
		/**
		 * @brief	获取该人想要停留的时间
		 *
		 * @return	
		 */
		int getTimeToRemain();
		/**
		 * @brief	增加停留时间
		 */
		void increaseTimeRemaining();
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
		 * @brief	已经停留的时间	
		 */
		int time_remaining;
		/**
		 * @brief	要停留的时间
		 */
		int time_to_remain;
		/**
		 * @brief	乘坐电梯的次数
		 */
		int count_in;
		/**
		 * @brief	乘坐电梯的最大次数
		 */
		int count_max_in;
};

#endif
