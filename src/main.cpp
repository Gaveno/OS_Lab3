/****************************
 *  Lab 3 - Simulating Page
 *  Replacement Algorithms.
 *  Author: Gavin Atkin
 *  Date: 11/20/2017
 ****************************/
 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "fifo.h"
#include "lru.h"
#include "lfu.h"
#include "opt.h"

using namespace std;

ostream &printOut(ostream &os, string framesize,
              const OutputResults &fifo, const OutputResults &lru,
              const OutputResults &lfu, const OutputResults &opt);


int main(int argc, const char* argv[]) {
    int rcode = 0;
    try {
        // Ensure enough arguments provided.
        if (argc != 4) {
            throw EXSimple("Incorrect number of arguments given.");
        }
        
        // Vector to hold string of ints.
        vector<int> pagestring;
        
        // Read in all values from the input file.
        ifstream infile(argv[2]);
        if (infile.is_open()) {
            while (infile.good()) {
                int input;
                infile >> input;
                pagestring.push_back(input);
            }
        }
        else
            throw EXSimple("Failed to open input file!");
        
        infile.close();
        
        // Perform Algorithms
        // FIFO
        AFIFO::FIFO fifo(stoi(argv[1]));
        OutputResults fifo_out;
        fifo_out = fifo.perform(pagestring, fifo_out);
        
        // LRU
        ALRU::LRU lru(stoi(argv[1]));
        OutputResults lru_out;
        lru_out = lru.perform(pagestring, lru_out);
        
        // LFU
        ALFU::LFU lfu(stoi(argv[1]));
        OutputResults lfu_out;
        lfu_out = lfu.perform(pagestring, lfu_out);
        
        // Optimal
        AOPT::OPT opt(stoi(argv[1]));
        OutputResults opt_out;
        opt_out = opt.perform(pagestring, opt_out);
        
        ofstream outfile(argv[3]);
        
        printOut(cout, argv[1], fifo_out, lru_out, lfu_out, opt_out);
        printOut(outfile, argv[1], fifo_out, lru_out, lfu_out, opt_out);
        
        outfile.close();
    }
    catch (EXSimple &ex) {
        cerr << ex;
        rcode = 1;
    }
    catch (EXNoFrames &ex) {
        cerr << ex;
        rcode = 2;
    }
    catch (...) {
        cerr << "\nError: Unknown exception caught.\n\n";
        rcode = 3;
    }

    return rcode;
}

ostream &printMultiple(ostream &os, char c, int num) {
    for (int i = 0; i < num; ++i) {
        os << c;
    }
    
    return os;
}

// Print ensuring maximum width is met.
ostream& printWidth(ostream& os, string str, unsigned int width) {
    os << str;
    if (str.length() < width) {
        for (unsigned int i = 0; i < width - str.length(); ++i) {
            os << " ";
        }
    }
    return os;
}

// Output resulting data
ostream &printOut(ostream &os, string framenumber,
              const OutputResults &fifo, const OutputResults &lru,
              const OutputResults &lfu, const OutputResults &opt) {
    
    os << setprecision(4);
    
    printMultiple(os, '=', 64);
    os << endl;
    os << "   Page Replacement Algorithm Simulation (frame size = " << framenumber;
    os << ")" << endl;
    printMultiple(os, '=', 64);
    os << endl;
    printMultiple(os, ' ', 30);
    os << "Page fault rates" << endl;
    os << "Algorithm  Total page faults  2000  4000  6000  8000  10000" << endl;
    
    // FIFO printout
    printWidth(os, "FIFO", 16);
    printWidth(os, to_string(fifo.totalPageFaults).substr(0, 6), 14);
    printWidth(os, to_string(fifo.rateAt2000).substr(0, 5), 6);
    printWidth(os, to_string(fifo.rateAt4000).substr(0, 5), 6);
    printWidth(os, to_string(fifo.rateAt6000).substr(0, 5), 6);
    printWidth(os, to_string(fifo.rateAt8000).substr(0, 5), 6);
    printWidth(os, to_string(fifo.rateAt10000).substr(0, 5), 6);
    os << endl;
    
    // LRU printout
    printWidth(os, "LRU", 16);
    printWidth(os, to_string(lru.totalPageFaults).substr(0, 6), 14);
    printWidth(os, to_string(lru.rateAt2000).substr(0, 5), 6);
    printWidth(os, to_string(lru.rateAt4000).substr(0, 5), 6);
    printWidth(os, to_string(lru.rateAt6000).substr(0, 5), 6);
    printWidth(os, to_string(lru.rateAt8000).substr(0, 5), 6);
    printWidth(os, to_string(lru.rateAt10000).substr(0, 5), 6);
    os << endl;
    
    // LFU printout
    printWidth(os, "LFU", 16);
    printWidth(os, to_string(lfu.totalPageFaults).substr(0, 6), 14);
    printWidth(os, to_string(lfu.rateAt2000).substr(0, 5), 6);
    printWidth(os, to_string(lfu.rateAt4000).substr(0, 5), 6);
    printWidth(os, to_string(lfu.rateAt6000).substr(0, 5), 6);
    printWidth(os, to_string(lfu.rateAt8000).substr(0, 5), 6);
    printWidth(os, to_string(lfu.rateAt10000).substr(0, 5), 6);
    os << endl;
    
    // Optimal printout
    printWidth(os, "Optimal", 16);
    printWidth(os, to_string(opt.totalPageFaults).substr(0, 6), 14);
    printWidth(os, to_string(opt.rateAt2000).substr(0, 5), 6);
    printWidth(os, to_string(opt.rateAt4000).substr(0, 5), 6);
    printWidth(os, to_string(opt.rateAt6000).substr(0, 5), 6);
    printWidth(os, to_string(opt.rateAt8000).substr(0, 5), 6);
    printWidth(os, to_string(opt.rateAt10000).substr(0, 5), 6);
    os << endl;
    
    return os;
}
