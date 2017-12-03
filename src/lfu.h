/***************************
 *  Least Frequently Used
 *  Virtual Memory Algorithm.
 ***************************/
 
#ifndef __LFU_H__
#define __LFU_H__

#include <vector>
#include "virtualmemory.h"

using namespace std;

typedef unsigned int uint;

namespace ALFU {

    bool compare(const PageFrame &i, const PageFrame &j);

    class LFU : public VirtualMemory {
    public:
        LFU( );
        LFU(uint pageframes);
        
        OutputResults &perform(vector<int> &pagestring, OutputResults &output) override;
    };
    
}

#endif