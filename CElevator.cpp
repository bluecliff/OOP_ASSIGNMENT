/**
 * @file CElevator.cpp
 * @brief	implementation of CElevator class
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-13
 */
#include "CElevator.h"

CElevator::CElevator(int kind,CBuilding* parent,int current_floor=1;int speed_running=elevator_speed_running,int speed_outin=elevator_speed_outin,int capacity=elevator_capacity)
{
	CElevator::count++;		//电梯实例增加1
	this->id=count;		//电梯id
	//初始状态
	this->to_floor=current_floor;
	this->status=halt;
	this->direction=false;
	passengers.clear();
}
CElevator::~CElevator()
{
	CElevator::count--;
}
bool CElevator::in(int i)
{
	//向乘员队列中插入一个乘客
	this->passengers.push_back(i);
	return true;
}
bool CElevator::out()
{
	list<int>::iterator first=this->passengers.begin();
	list<int>::iterator last=this->passengers.end();
	//从乘客队列中查找一个可以下的人，不存在则返回false
	while(first!=last)
	{
		int destination=this->parent->getPassengerById(*first)->getDestination();
		if(destination==this->current_floor)
		{
			//从队列中删除该乘客ID
			this->passengers.erase(first);
			return true;
		}
		++first;
	}
	return false;
}
