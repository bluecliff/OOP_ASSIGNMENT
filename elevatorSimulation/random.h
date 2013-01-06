#ifndef RANDOM_H_
#define RANDOM_H_
#include "stdlib.h"

void sort(int n,int* res)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(res[j]<res[j-1])
            {
                int temp=res[j];
                res[j]=res[j-1];
                res[j-1]=temp;
            }
            else
            {
                break;
            }
        }
    }
}
//把k球按均匀分布分成m堆，返回res
void my_random(int k,int m,int* res)
{
    //按组合数学的原理，模型是把k球分成m堆
    //首先产生m-1个0到k的整数
    if(m==1)
    {
        res[0]=k;
    }
    for(int i=0;i<m-1;i++)
    {
        res[i]=rand()%(k+1);
    }
    res[m-1]=k;
    //从小到大排序
    sort(m,res);
    //计算每个堆的大小
    for(int i=(m-1);i>0;i--)
    {
        res[i]=res[i]-res[i-1];
    }
}
#endif
