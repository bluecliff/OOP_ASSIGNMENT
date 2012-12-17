/**
 * @file CElevator.cpp
 * @brief	implementation of CElevator class
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-13
 */
#include "CElevator.h"

CElevator::count=0;
CElevator::CElevator(int kind,CBuilding* parent,int current_floor=1;int speed_running=elevator_speed_running,int speed_outin=elevator_speed_outin,int capacity=elevator_capacity)
{
	this->id=count;		//电梯id
	//初始状态
	this->current_floor.floor=current_floor;
	this->current_floor.time_past=0;
	this->status=halt;
	this->direction=false;
	memset(this->to_floor,0,sizeof(bool)*max_floors);
	passengers.clear();
	CElevator::count++;		//电梯实例增加1
}
CElevator::~CElevator()
{
	CElevator::count--;
}
bool CElevator::in(int i)
{
	//向乘员队列中插入一个乘客
	this->passengers.push_back(i);
	//更新停靠表
	this->to_floor[parent->getPassengerById[i]->getDestination()]=true;
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
	//该层从电梯停靠表中删除
	this->to_floor[this->current_floor.floor]=false;
	return false;
}
void CElevator::run()
{
	//电梯开始运行
	if(this->status==waiting)
	{
		this->status=running;
	}
}
void CElevator::haltdown()
{
	if(this->status==waiting)
	{
		this->status=halt;
	}
}
void CElevator::stop()
{
	if(this->status==running)
	{
		this->status=waiting;
	}
}
void CElevator::startup()
{
	if(this->status==haltdown)
	{
		this->status=waiting;
	}
}
elevator_status CElevator::getElevatorStatus()
{
	return this->status;
}
int CElevator::getCurrentFloor()
{
	if(this->current_floor.time_past==0)
	{
		return this->current_floor.floor;
	}
	else
	{
		return -1;
	}
}
//需要处理边界条件
void CElevator::onClock()
{
	this->current_floor.time_past++;
	this->current_floor.time_past%=elevator_speed_running;
	if(this->current_floor.time_past==0)
	{
		if(this->direction)
		{
			this->current_floor.floor++;
		}
		else
		{
			this->current_floor.floor--;
		}
	}
}
