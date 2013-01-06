#include "CElevator.h"
#include "CBuilding.h"
bool CElevator::kinds[5][40]={

    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},

};
int CElevator::speed=1;
int CElevator::capacity=10;
int CElevator::timeOutIn=1;
CElevator::CElevator(int kind_) {
	kind=kind_;
	mpos = 0;
	fpos=0;
	doorStatus = 0;
    dir = '-';
    timeMoving=0;
}

/* 得到电梯乘客人数 */
int CElevator::Get_nPassenger() {
	return passengers.size();
}

/* 得到电梯方向 */
char CElevator::Dir() {
    return dir;
}

int CElevator::Get_fpos()
{
    return fpos;
}

int CElevator::Get_mpos()
{
    return mpos;
}

/* 控制电梯移动 */
void CElevator::Move()
{
    if(doorStatus)
        return;
    if(instructions.empty())
        return;
    //int inst=instructions.back()->dest;
    if(fpos!=0)
        return;
    list <CInstruction*>::iterator iter;
    for(iter=instructions.begin();iter!=instructions.end();iter++)
    {
        if((*iter)->dest==mpos)
            break;
    }
    //处于停靠楼层
    //if(mpos==inst && fpos==0)
    if(iter!=instructions.end())
    {
        //改变电梯状态,并且删除已经完成的指令
        dir='-';
        doorStatus=1;
        instructions.erase(iter);
    }
    else
    {
        //非停靠楼层，继续运行电梯
        timeMoving++;
        doorStatus=0;
        int inst=instructions.front()->dest;
        //上行
        if(mpos<inst)
        {
            //向上运行
            fpos++;
            if(fpos==CElevator::speed)
            {
                fpos=0;
                mpos++;
            }
            dir='^';
        }
        else
        {
            //向下运行
            if(mpos==inst)
            {
                fpos--;
            }
            else if(mpos>inst)
            {
                if(fpos==0)
                {
                    fpos=CElevator::speed-1;
                    mpos--;

                }
                else
                {
                    fpos--;
                }
            }
            dir='v';
        }

    }
}

/* 让目的地为当前位置的乘客出电梯 */
void CElevator::Letout() {
    for(std::list<CPassenger*>::iterator iter = passengers.begin(); iter != passengers.end(); iter++)
    {
        if((*iter)->Get_to() == mpos)
        {
            if(!((*iter)->Arrive()))
            {
                CPassenger* pass=*iter;
                passengers.erase(iter);
                iter--;
                //delete pass;
                CBuilding::outPassengers.push_back(pass);
            }
            else
            {
                CBuilding::floors[mpos].PushPassenger(*iter);
                passengers.erase(iter);
                iter--;
            }
        }
    }
    //passengers.remove_if( to_is_pos(pos) );
}

/* 让乘客进入 */

/////需要重写，考虑电梯的运行状态和该楼层的人员等待状态
void CElevator::Letin(int dirCode) {
    CFloor* floor = &CBuilding::floors[mpos];
    while(passengers.size()< (unsigned)capacity)
    {
        CPassenger* pass=floor->PopPassenger(dirCode);
        if(pass!=NULL)
        {
            passengers.push_back(pass);
            if(dirCode==1)
            {
                if(pass->Get_to()>mpos)
                {
                    dirCode=2;
                }
                else
                {
                    dirCode=3;
                }
            }
        }
        else
        {
            break;
        }
    }
    switch(dirCode) {
        case 1:
            floor->CancelOrder('^');
            floor->CancelOrder('v');
            break;
        case 2:
            floor->CancelOrder('^');
            break;
        case 3:
            floor->CancelOrder('v');
            break;
        default:
            break;
    };

    this->doorStatus=0;
    this->UpdateInstructions(dirCode);
    floor->CheckOrder();
}

//乘客上下电梯
void CElevator::OutIn()
{
    if(doorStatus==0)
        return;
    //电梯门开着的才可以进出
    Letout();
    int dirCode;//=instructions.front()->dirCode;
    if(instructions.empty())
        dirCode=1;
    else
        dirCode=instructions.front()->dirCode;
    Letin(dirCode);
}

/* 指令入栈 */
void CElevator::PushInst(CInstruction* inst) {
    list<CInstruction*>::iterator iter;

    for(iter=instructions.begin();iter!=instructions.end();iter++)
    {
        //若已经有相同的指令在栈中，则删除该指令
        if((*iter)->dest==inst->dest)
        {
            delete inst;
            return;
        }
    }
    instructions.push_back(inst);
}

///* 取出指令 */
list<CInstruction*> *CElevator::Get_inst()
{
    return &instructions;
}
////更新指令队列
void CElevator::UpdateInstructions(int dirCode)
{
    list<CPassenger*>::iterator iter;
    for(iter=passengers.begin();iter!=passengers.end();iter++)
    {
        PushInst(new CInstruction((*iter)->Get_to(),dirCode));
    }
}
