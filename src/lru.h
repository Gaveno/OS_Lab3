/***************************
 *  Least Recently Used
 *  Virtual Memory Algorithm.
 ***************************/
 
#ifndef __LRU_H__
#define __LRU_H__

#include <vector>
#include "virtualmemory.h"

using namespace std;

typedef unsigned int uint;

namespace ALRU {

    bool compare(const PageFrame &i, const PageFrame &j);

    class LRU : public VirtualMemory {
    public:
        LRU( );
        LRU(uint pageframes);
        
        OutputResults &perform(vector<int> &pagestring, OutputResults &output) override;
    };
    
}

#endif