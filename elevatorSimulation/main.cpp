/* main function file */
#include "CPassenger.h"
#include "CBuilding.h"
#include "CElevator.h"
#include "CController.h"
#include "random.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
#include <stdlib.h>
//#include <time.h>

#define DEBUG 0
#if DEBUG
#include <fstream>
ofstream logout("log.txt");
int k_DEBUG=0;
#endif
/* Born函数用于生成n个乘客插入0层的等待队列 */
void Born(int n) {
    for(int i=0;i<n;i++)
    {
        CPassenger* pass = new CPassenger();
        CBuilding::floors[0].PushPassenger(pass);
    }
}

/* 电梯移动的实现 */
void Move() {
    vector<CElevator*>::iterator iter;
    //EleIter iter;
    for(iter = CBuilding::elevators.begin(); iter != CBuilding::elevators.end(); iter++)
    {
        (*iter)->Move();
        #if DEBUG
        logout<<CBuilding::times<<":CBuilding::elevators["<<k_DEBUG<<"].Move();"<<endl;
        k_DEBUG++;
        #endif
    }
}

/* 乘客等待状态与电梯运行状态的更新 */
void Update() {
    //EleIter iter;
    vector<CElevator*>::iterator iter;
    for (int i = 0; i < CBuilding::nFloor; i++) {
        CBuilding::floors[i].LetThemWait();
        #if DEBUG
        logout<<CBuilding::times<<":CBuilding::floors["<<i<<"].LetThemWait();"<<endl;
        #endif
        CBuilding::floors[i].CheckOrder();
        #if DEBUG
        logout<<CBuilding::times<<":CBuilding::floors["<<i<<"].CheckOrder();"<<endl;
        #endif
    }
    for (iter = CBuilding::elevators.begin(); iter != CBuilding::elevators.end(); iter++) {
        (*iter)->OutIn();
        #if DEBUG
        logout<<CBuilding::times<<":CBuilding::elevators["<<k_DEBUG<<"].OutIn();"<<endl;
        k_DEBUG++;
        #endif
    }

}

void print()
{
    int totalWaitingPassengers=0;
    int totalStayingPassengers=0;
    int totalMovingPassengers=0;

    cout <<" Floor"<<" SPassenger"<<" WPassenger";
	for(int i = 0; i < CBuilding::nElevator; i++)
	{
		cout <<"    E-"<<i<<" ";
		totalMovingPassengers+=CBuilding::elevators[i]->Get_nPassenger();
	}
	cout << endl;

    for(int i=CBuilding::nFloor-1;i>=0;i--)
    {
        cout<<setw(6)<<i<<setw(11)<<CBuilding::floors[i].Get_SPassenger()<<setw(11)<<CBuilding::floors[i].Get_WPassenger();
        vector<CElevator*>::iterator iter;
        for(iter = CBuilding::elevators.begin(); iter != CBuilding::elevators.end(); iter++)
        {
			if((*iter)->Get_mpos() == i)
                printf("   \033[32m[%2d]%c\033[0m", (*iter)->Get_nPassenger(), (*iter)->Dir());
                //cout<<"   ["<<setw(2)<<(*iter)->Get_nPassenger()<<']'<<(*iter)->Dir();
			else
				cout<<setw(8)<<" ";
		}
		cout<<endl;
		totalStayingPassengers+=CBuilding::floors[i].Get_SPassenger();
		totalWaitingPassengers+=CBuilding::floors[i].Get_WPassenger();
    }
    cout<<"time: "<<CBuilding::times<<endl;

    cout<<"elevators' idle time and running time:"<<endl;
    for(int i=0; i<CBuilding::nElevator; i++)
    {
        cout<<"E"<<i<<" "<<CBuilding::times-CBuilding::elevators[i]->timeMoving<<"/"<<CBuilding::elevators[i]->timeMoving<<"   ";
    }
    cout<<endl;

    cout<<"the total staying passengers: "<<totalStayingPassengers<<endl;
    cout<<"the total waiting passengers: "<<totalWaitingPassengers<<endl;
    cout<<"the total moving passengers: "<<totalMovingPassengers<<endl;
    cout<<"the total passengers now: "<<(totalMovingPassengers+totalStayingPassengers+totalWaitingPassengers)<<endl;

    list<CPassenger*>::iterator liter;
    for(liter=CBuilding::outPassengers.begin();liter!=CBuilding::outPassengers.end();liter++)
    {
        cout<<"passenger numbered "<<(*liter)->id<<" left building, he's waiting time is: "<<(*liter)->Get_timeWait()<<endl;
    }
}

int main(int argc, char *argv[])
{
    /* 根据当前时间生成随机数种子 */
    //srand(time(NULL));

    CBuilding::times= 0;
    CBuilding::nElevator = 10;
    CBuilding::nFloor=40;


	int K,N,M,S,T;
	K=15;//每部电梯的最大载人数目
	N=300;//总共乘坐电梯人数
	M=60;//乘客的分布时间
	S=1;//电梯的运行速度S秒每层
	T=1;//乘客的上下速度

    /* CPassenger和CElevator静止成员声明 */
    CElevator::capacity = K;
    CElevator::timeOutIn = T;
    CElevator::speed = S;

    //初始化没分钟的生成的乘客数目
    int* dis=new int[M];
    my_random(N,M,dis);

    /* 初始化电梯 */
    for(int i = 0; i < CBuilding::nElevator; i++) {
        CElevator* ele = new CElevator(i/2);//初始化为相应的电梯类别
        CBuilding::elevators.push_back(ele);
    }


    while(1)
    {
        //生成乘客
        if(CBuilding::times<M)
        {
            Born(dis[CBuilding::times]);
        }
        #if DEBUG
        if (CBuilding::times==96)
            system("pause");
        #endif
        //调度电梯
        CController::dispatch();
        //电梯响应move事件
        Move();
        //乘客状态与电梯状态更新
        Update();
        //打印状态变化结果
        system("clear");
        print();
        system("sleep 1");
        CBuilding::times++;
    }

    delete[] dis;
    return 0;
}
