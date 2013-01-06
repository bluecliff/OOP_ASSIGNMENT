#ifndef CINSTRUCTION_H_
#define CINSTRUCTION_H_
/* 电梯指令，调度程序的的输出 */
class CInstruction
{
public:
    CInstruction(int dest_, int dirCode_) : dest(dest_), dirCode(dirCode_){};
    int dest;           /* 指令目的地 */

    int dirCode;        /* 指令的载人方向
                         * 1: 中途开门接受上、下两个方向乘客
                         * 2: 中途开门只接受向上的乘客
                         * 3: 中途开门只接受向下的乘客
                         */
};

#endif
