/***************************
 *  Virtual Memory Class
 *  Base for the various
 *  algorithms.
 ***************************/
 
#ifndef __VIRTUAL_MEMORY_H__
#define __VIRTUAL_MEMORY_H__

#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned int uint;

struct PageFrame {
    int pageID;
    uint usedAt;
    uint timesUsed;
    uint firstUsed;
    uint nextUsed;
};

struct OutputResults {
    uint totalPageFaults;
    float rateAt2000;
    float rateAt4000;
    float rateAt6000;
    float rateAt8000;
    float rateAt10000;
};

class EXSimple {
public:
    EXSimple(string message) : error(message) {};
    friend ostream &operator<<(ostream &os, EXSimple &ex);
protected:
    string error;
};

class EXNoFrames {
public:
    EXNoFrames( ) {}
    friend ostream &operator<<(ostream &os, EXNoFrames &ex);
};

class VirtualMemory {
public:
    VirtualMemory( );
    VirtualMemory(uint numframes);
    
    void setNumberFrames(uint numframes);
    void setupPages( );
    
    virtual OutputResults &perform(vector<int> &pagestring, OutputResults &output) = 0;
    
protected:
    uint pageFaults;
    uint hits;
    uint numFrames;
    vector<PageFrame> pageFrames;
};

#endif