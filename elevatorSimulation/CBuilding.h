#ifndef CBUILDING_H_
#define CBUILDING_H_

//class CFloor;
//typedef std::list<CRequest*>::iterator ReqIter;
#include "./CElevator.h"
#include "./CFloor.h"
#include "./CRequest.h"
class CElevator;
class CFloor;
class CRequest;
class CBuilding
{

public:
    CBuilding();

    static int times;                        /* 整个过程花费的时间 */

    static int nElevator;                   /* 电梯总数 */

    static std::vector<CElevator*> elevators;     /* 所有的电梯 */

    static CFloor floors[40];                /* 楼层 */
    //static CFloor floors;
    static int nFloor;                      /* 总楼层数 */

    static std::list<CRequest*> requests;        //个楼层的请求队列

    static std::list<CPassenger*> outPassengers;    //离开电梯的乘客
};

//CFloor* CBuilding::floors=new CFloor[40];
#endif
