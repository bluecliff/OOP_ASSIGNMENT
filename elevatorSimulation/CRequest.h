#ifndef CREQUEST_H_
#define CREQUEST_H_
#include "./CPassenger.h"
class CRequest
{
    public:
        CRequest(CPassenger* pass);
    //CFloor *floor;               /* 请求发出楼层的引用 */
    int from;                   /* 请求发出的楼层 */
    char dir;                   /* 请求希望去的方向, 'v': 向下, '^': 向上 */
};
#endif
