#include "./CRequest.h"
CRequest::CRequest(CPassenger* pass)
{
        from=pass->Get_from();
        int to = pass->Get_to();
        if(to >= from) dir = '^';
        else dir = 'v';

        //floor = &(CBuilding::floors[from]);
}
