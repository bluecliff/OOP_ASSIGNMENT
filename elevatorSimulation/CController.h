#ifndef CCONTROLLER_H_
#define CCONTROLLER_H_


#include <vector>

/* 找寻空闲的电梯，空闲电梯是指停留着的没有指令的没有载客的电梯，如果没有找到这样的电梯返回 NULL */
void Idle(vector<CElevator*>& idle )
{
    std::vector<CElevator*>::iterator iter;

    for(iter = CBuilding::elevators.begin(); iter != CBuilding::elevators.end(); iter++)
    {
        if((*iter)->Dir() == '-' && (*iter)->Get_nPassenger() == 0 && (*iter)->Get_inst()->size() == 0)
            //return *iter;
            idle.push_back(*iter);
    }
}

class CController
{
    public:
        static void dispatch()
        {
             /* 设置电梯默认运行方向为上下两个方向 */
           //CElevator::defaultDir = 1;
            vector<CElevator*> idle;
            Idle(idle);

            for(vector<CElevator*>::iterator i=idle.begin();i!=idle.end();i++)
            {
                for(list<CRequest*>::iterator j=CBuilding::requests.begin();j!=CBuilding::requests.end();j++)
                {
                    if(CElevator::kinds[(*i)->kind][(*j)->from])
                    {
                        //给i电梯下达执行j请求的指令
                        (*i)->PushInst(new CInstruction((*j)->from,1));
                        CBuilding::requests.erase(j);
                        break;
                    }
                }
            }
        }
};
#endif
