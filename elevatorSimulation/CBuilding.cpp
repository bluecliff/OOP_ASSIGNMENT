#include "CBuilding.h"
CBuilding::CBuilding()
{
}
CFloor CBuilding::floors[40];
int CBuilding::times=0;
int CBuilding::nElevator=10;
int CBuilding::nFloor=40;
std::vector<CElevator*> CBuilding::elevators;
std::list<CRequest*> CBuilding::requests;
std::list<CPassenger*> CBuilding::outPassengers;
//CPassenger* CBuilding::outPassenger=NULL;
