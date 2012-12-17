/**
 * @file CFloor.cpp
 * @brief	实现楼层类
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-12-17
 */
#include "CFloor.h"
CFloor::count=0;
CFloor::CFloor(CBuilding* parent)
{
	this->id=CFloor::count;
	this->count++;
}
CFloor::~CFloor()
{
	CFloor::count--;
}
void CFloor::outWaitingList(int i)
{
	list<int>::iterator first=this->waitingList.begin();
	list<int>::iterator last=this->waitingList.end();
	while(first!=last)
	{
		if (this->waitingList[first]==i)
		{
			this->waitingList.erase(first);
			return ;
		}
		++first;
	}
}
void CFloor::inStayingList(int i)
{
	this->stayingList.push_back(i);
}
void CFloor::updatePassengeList()
{
	list<int>::iterator first=this->stayingList.begin();
	list<int>::iterator end=this->stayingList.end();
	while(first!=last)
	{
		CPassenger* passenger=parent->getPassengerByID(stayingList[first]);
		if(passenger->getTimeRemaining >=passenger->getTimeToRemain())
		{
			this->waitingList.push_back(stayingList[first]);
			first=this->stayingList.erase(first);
		}
		else
		{
			first++;
		}

	}
}
int CFloor::getWaitListSize()
{
	return this->waitingList.size();
}
int CFloor::getStayingListSize()
{
	return this->stayingList.size();
}
