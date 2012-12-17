/**
 * @file CPassenger.cpp
 * @brief	CPassenger类的实现
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-17
 */
#include "CPassenger.h"
CPassenger::count=0;
CPassenger::CPassenger(int destination,int time_to_remain,int count_max_in)
{
	this->id=CPassenger::count;
	this->time_remaining=0;
	this->count_in=0;
	this->count++;
}
CPassenger::~CPassenger()
{
	CPassenger::count--;
}
void CPassenger::init(int destination,int time_to_remain)
{
	//重新初始化成员并更新已经乘坐次数
	this->destination=destination;
	this->time_to_remain=time_to_remain;
	this->time_remaining=0;
	this->count_in++;
}
int CPassenger::getDestination()
{
	return this->destination;
}

int getTimeRemaining()
{
	return this->time_remaining;
}

int getTimeToRemain()
{
	return this->time_to_remain;
}
void increaseTimeRemaining()
{
	this->time_remaining++;
}
