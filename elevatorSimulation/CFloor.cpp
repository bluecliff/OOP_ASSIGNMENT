#include "CFloor.h"
#include "CPassenger.h"
#include "CBuilding.h"
CFloor::CFloor()
{
    upOrder=NULL;
    downOrder=NULL;
}
/* 让新乘客p进入该层 */
void CFloor::PushPassenger(CPassenger *p)
{
	stayingPassengers.push_back(p);
}

/* 获得该层的乘客总量 */
int CFloor::Get_WPassenger()
{
    return waitingPassengers.size();
}
int CFloor::Get_SPassenger()
{
    return stayingPassengers.size();
}

//获取一个符合电梯运行方向的乘客并使之出列
CPassenger* CFloor::PopPassenger(int dirCode)
{
    if(this->waitingPassengers.size()>0)
    {
        CPassenger* pass=NULL;
       list<CPassenger*>::iterator iter;
        switch(dirCode)
        {
            case 1:
                pass=waitingPassengers.front();
                waitingPassengers.pop_front();
                break;
            case 2:
                for(iter=waitingPassengers.begin();iter!=waitingPassengers.end();iter++)
                {
                    if((*iter)->Get_to()>(*iter)->Get_from())
                    {
                        pass=*iter;
                        waitingPassengers.erase(iter);
                        break;
                    }
                }
                break;
            case 3:
                for(iter=waitingPassengers.begin();iter!=waitingPassengers.end();iter++)
                {
                    if((*iter)->Get_to()<(*iter)->Get_from())
                    {
                        pass=*iter;
                        waitingPassengers.erase(iter);
                        break;
                    }
                }
                break;
            default:
                break;
        }
        return pass;
    }
    else
    {
        return NULL;
    }
}
/* 使该层乘客等待 */
void CFloor::LetThemWait() {
    list<CPassenger*>::iterator iter;
    for(iter = waitingPassengers.begin(); iter != waitingPassengers.end(); iter++) {
        (*iter)->Wait();
    }

    for(iter = stayingPassengers.begin(); iter !=stayingPassengers.end(); iter++) {
        (*iter)->Wait();
    }
    for(iter = stayingPassengers.begin();iter!=stayingPassengers.end();iter++)
    {
        //若停留时间到了，加入等待队列
        if((*iter)->Get_timeToStay()==0)
        {
            waitingPassengers.push_back(*iter);
            stayingPassengers.erase(iter);
            iter--;
        }
    }
}

/* 返回该层是否有请求 */
bool CFloor::Ordered() {
    return UpOrdered() || DownOrdered();
}

/* 设置上楼请求 */
void CFloor::Set_upOrder(CRequest* order) {
    upOrder = order;
}

/* 设置下楼请求 */
void CFloor::Set_downOrder(CRequest* order) {
    downOrder = order;
}

/* 返回是否有上楼请求 */
bool CFloor::UpOrdered() {
    return upOrder != NULL;
}

/* 返回是否有下楼请求 */
bool CFloor::DownOrdered() {
    return downOrder != NULL;
}

/* 取消请求 */
void CFloor::CancelOrder(char dir) {
    list<CRequest*>::iterator iter;
    CRequest* order;
    if (dir == '^') {
        order = upOrder;
        upOrder = NULL;
    } else {
        order = downOrder;
        downOrder = NULL;
    }
    for(iter = CBuilding::requests.begin(); iter != CBuilding::requests.end(); iter++)
    {
        if (*iter == order) {
            CBuilding::requests.erase(iter);
            return;
        }
    }
}

//检查等待的乘客中是否有需要发出请求
void CFloor::CheckOrder()
{
    if(Ordered())
    {
       return;
    }
    if(!UpOrdered())
    {
        list<CPassenger*>::iterator iter;
        for(iter = waitingPassengers.begin(); iter != waitingPassengers.end(); iter++)
        {
            if((*iter)->Get_to() > (*iter)->Get_from())
            {
                this->Set_upOrder(new CRequest(*iter));
                CBuilding::requests.push_back(upOrder);
                break;
            }
        }
    }

    if(!DownOrdered())
    {
        list<CPassenger*>::iterator iter;
        for(iter = waitingPassengers.begin(); iter != waitingPassengers.end(); iter++)
        {
            if((*iter)->Get_to() < (*iter)->Get_from())
            {
                this->Set_downOrder(new CRequest(*iter));
                CBuilding::requests.push_back(downOrder);
                break;
            }
        }
    }
}
