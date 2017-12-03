/***************************
 *  First In First Out
 *  Virtual Memory Algorithm.
 ***************************/
 
#ifndef __FIFO_H__
#define __FIFO_H__

#include <vector>
#include "virtualmemory.h"

using namespace std;

typedef unsigned int uint;

namespace AFIFO {

    bool compare(const PageFrame &i, const PageFrame &j);

    class FIFO : public VirtualMemory {
    public:
        FIFO( );
        FIFO(uint pageframes);
        
        OutputResults &perform(vector<int> &pagestring, OutputResults &output) override;
    };
    
}

#endif