/***************************
 *  Virtual Memory Class
 *  Base for the various
 *  algorithms.
 ***************************/
 
#include "virtualmemory.h"

VirtualMemory::VirtualMemory( ) {
    pageFaults = 0;
    hits = 0;
    numFrames = 0;
}

VirtualMemory::VirtualMemory(uint numframes) : VirtualMemory( ) {
    setNumberFrames(numframes);
    setupPages( );
}

void VirtualMemory::setNumberFrames(uint numframes) {
    numFrames = numframes;
}

void VirtualMemory::setupPages( ) {
    if (numFrames == 0) throw EXNoFrames();
    
    for (uint i = 0; i < numFrames; ++i) {
        PageFrame newpage = {-1, 0, 0, 0, 10000};
        pageFrames.push_back(newpage);
    }
}

ostream &operator<<(ostream &os, EXNoFrames &ex) {
    os << "\nException Thrown: No frames initialized.\n\n";
    return os;
}

ostream &operator<<(ostream &os, EXSimple &ex) {
    os << "\nCaught Exception: " << ex.error << "\n\n";
    return os;
}