/***************************
 *  Optimal
 *  Virtual Memory Algorithm.
 ***************************/
 
#ifndef __OPT_H__
#define __OPT_H__

#include <vector>
#include "virtualmemory.h"

using namespace std;

typedef unsigned int uint;

namespace AOPT {

    bool compare(const PageFrame &i, const PageFrame &j);

    class OPT : public VirtualMemory {
    public:
        OPT( );
        OPT(uint pageframes);
        
        OutputResults &perform(vector<int> &pagestring, OutputResults &output) override;
    };
    
}

#endif