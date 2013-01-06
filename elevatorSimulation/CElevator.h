#ifndef CELEVATOR_H_
#define CELEVATOR_H_

#include <vector>
#include <list>

#include "CPassenger.h"
#include "CInstruction.h"
/* 电梯基类 */
class CElevator
{
    friend class CControllor;
    friend class CBuilding;
public:
    int kind;               //电梯种类
	int mpos;       //电梯位置
    int fpos;
	bool doorStatus;                        /* 0: close, 1: open */
    int timeMoving;

    static int timeOutIn;              /* 上下乘客所需时间 */

    static int capacity;                    /* 电梯最大容量 */

    static int speed;                           /* 电梯速度*/

    char dir;                               /* 电梯运动方向 */

    std::list<CPassenger*> passengers;       /* 电梯内乘客 */

    std::list<CInstruction*> instructions;   /* 电梯现有指令栈 */

    void Letout();                          /* 让乘客离开 */

    void Letin(int cancelCode);             /* 让乘客进入 */

    //void OpenDoor();                        /* 电梯开门 */

    //void CloseDoor();                       /* 电梯关门 */

    //int defaultDir;                  /* 电梯默认接客方向 */

public:
	CElevator(int kind_);                             /* 构造函数 */

    void OutIn();                     /* 乘客上下电梯 */

	int Get_mpos();                          /* 获得当前所在位置  */

    int Get_fpos();                      /* 获得所在浮点数位置，*/

	int Get_nPassenger();                   /* 获得现有乘客数     */

    char Dir();                             /* 获得方向: ^: upwards, v: downwards, -: stopping */

    //void ToggleDoor();                      /* 开/门 */

	void Move();                            /* 电梯依据指令栈顶移动，否则按照随即顺序移动 */

    void PushInst(CInstruction*);            /* 添加指令 */
    void UpdateInstructions(int dirCode);          //乘客进入，关门后更新指令队列

    std::list<CInstruction*> *Get_inst();    /* 得到指令栈的指针 */
    //CInstruction* Get_instruction();

    //static int Get_capacity();              /* 获得最大乘客量 */

    //static void Set_defaultDir(int dir);    /* 设置默认行进方向 */

    //static int Get_defaultDir();            /* 获得默认行进方向 */

    static bool kinds[5][40];
};

#endif
