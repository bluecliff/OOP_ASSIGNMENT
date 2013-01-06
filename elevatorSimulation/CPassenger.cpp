#include "CPassenger.h"
#include "CBuilding.h"

#include <stdlib.h>

//最少和最多停留时间
#define MAX_TIME 120
#define MIN_TIME 10
//乘坐次数
#define TIMES 10

int CPassenger::num=0;

CPassenger::CPassenger()
{
    timeWait=0;
    timeToStay=rand()%(MAX_TIME-MIN_TIME)+MIN_TIME;
    from=0;
    while((to=rand()%40)==0){};
    count=rand()%TIMES+1;
    id=num;
    num++;
}

int CPassenger::Get_from()
{
    return from;
}

int CPassenger::Get_to()
{
    return to;
}
//乘客停留一段时间
void CPassenger::Wait()
{
    if(timeToStay==0)
    {
        timeWait++;
    }
    else
    {
        timeToStay--;
    }
}
//获取乘客停留时间
int CPassenger::Get_timeToStay()
{
    return timeToStay;
}
//乘客到达目的楼层，重新初始化
bool CPassenger::Arrive()
{
    count--;//乘坐次数减少一次
    if(count<0)
    {
        //把该乘客清除
        //if(CBuilding::outPassenger!=NULL)
        //    delete CBuilding::outPassenger;
        //CBuilding::outPassenger=this;
        //CBuilding::outPassenger(this);
        return false;
    }
    if(count==0)
    {
        //最后一次到到0楼
        from=to;
        to=0;
        timeToStay=rand()%(MAX_TIME-MIN_TIME)+MIN_TIME;
        return true;
    }
    else
    {
        //新的状态
        from=to;
        while((to=rand()%40)==from){};
        timeToStay=rand()%(MAX_TIME-MIN_TIME)+MIN_TIME;
        return true;
    }
}
//返回改成可用于等待电梯的时间
int CPassenger::Get_timeWait()
{
    return timeWait;
}
