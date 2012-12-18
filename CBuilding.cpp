
#include "CBuilding.h"
CBuilding::CBuilding()
{
	
}
CBuilding::~CBuilding()
{
}
void CBuilding::init()
{
	for(int i=0;i<max_floors;i++)
	{
		floors[i]=new CFloor();
	}
	for(int i=0;i<elevator_count;i++)
	{
		elevators[i]=new CElevator();
	}
	for(int i=0;i<passenger_max;i++)
	{
		passengers[i]=new CPassenger();
	}
}
void CBuilding::destroy()
{
	for(int i=0;i<max_floors;i++)
	{
		delete floors[i];
	}
	for(int i=0;i<elevator_count;i++)
	{
		delete elevators[i];
	}
	for(int i=0;i<passenger_max;i++)
	{
		delete passengers[i];
	}
}
void CBuilding::onClick()
{

}
