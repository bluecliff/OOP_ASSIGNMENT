#ifndef CPASSENGER_H_
#define CPASSENGER_H_


#include <algorithm>
#include <climits>


class CPassenger
{
    friend class CBuilding;
private:
	int timeWait;                       /* 每个乘客等待时间 */

	int from;                           /* 出发地 */

	int to;                             /* 目的地 */

    int timeToStay; //在该楼层的欲停留时间,减为0即成为等待状态

    int count;  //乘坐电梯的次数，若为0，则不再乘坐电梯，直接到楼删

public:

    int id; //乘客标识

	CPassenger();               /* 构造一个乘客 */

	int Get_from();						/* 获得乘客来自的楼层 */

	int Get_to();                       /* 获得乘客去往的楼层 */

	void Wait();               /* 等待t个单位时间  */

	int Get_timeToStay();

	int Get_timeWait();

	bool Arrive();                      /* 乘客到达目的地时执行的函数 */

    static int num; //类实体的数量
};
#endif
