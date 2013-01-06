#ifndef CFLOOR_H_
#define CFLOOR_H_

#include <list>

//#include "./CRequest.h"
//#include "./CBuilding.h"
class CPassenger;

class CRequest;
using namespace std;

class CFloor
{
    friend class CPassenger;
    friend class CBuilding;
private:
	std::list<CPassenger*> waitingPassengers;                /* 楼层等待中的乘客 */

    std::list<CPassenger*> stayingPassengers;              /* 停留的乘客 */

    CRequest* upOrder;                             /* 楼层向上的请求，相当于按下的向上按钮 */

    CRequest* downOrder;                           /* 楼层的向下请求，相当于按下的向下按钮 */
public:
	CFloor();                                    /* 构造函数 */

	void PushPassenger(CPassenger *p);           /* 让一个新乘客p进入楼层 */

    int Get_SPassenger();                       /* 获得该层等待乘客总量 */
    int Get_WPassenger();

    CPassenger *PopPassenger(int dirCode);                  /* 获得一个符合电梯运行方向的乘客并使之出队 */

    CPassenger *FrontPassenger();                /* 获得队首乘客 */

    void LetThemWait();                         /* 让乘客等一个单位时间 */

    bool Ordered();                             /* 如果该层请求了电梯则返回true */

    void Set_downOrder(CRequest* order);           /* 设置下楼的请求 */

    void Set_upOrder(CRequest* order);             /* 设置向上的请求 */

    bool UpOrdered();                           /* 返回向上按钮是否被按（是否有向上请求） */

    bool DownOrdered();                         /* 返回向下按钮是否被按（是否有向下请求） */

    void CancelOrder(char dir);                 /* 取消 dir 方向的请求 */

    void CheckOrder();                          /* 楼层检查是否有乘客要去某方向，但是这个方向的按钮没有被按，如果有这种情况，就让该乘客请求一部电梯 */

};
#endif
