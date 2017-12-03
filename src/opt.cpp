/***************************
 *  Optimal
 *  Virtual Memory Algorithm.
 ***************************/
 
#include <algorithm>
#include "opt.h"

namespace AOPT {
 
    OPT::OPT( ) : VirtualMemory( ) {

    }

    OPT::OPT(uint pageframes) : VirtualMemory(pageframes) {

    }

    OutputResults &OPT::perform(vector<int> &pagestring, OutputResults &output) {
        // Loop through pagestring vector.
        for (uint i = 0; i < pagestring.size(); ++i) {
            // Loop through pageFrames to find free page.
            uint j;
            for (j = 0; j < pageFrames.size(); ++j) {
                // Check already there.
                if (pageFrames[j].pageID == pagestring[i]) {
                    ++pageFrames[j].timesUsed;
                    ++hits;
                    break;
                }
                else if (pageFrames[j].pageID == -1) {
                    // If got to empty before finding self, add.
                    pageFrames[j].pageID = pagestring[i];
                    ++pageFrames[j].timesUsed;
                    pageFrames[j].firstUsed = i;
                    ++pageFaults;
                    break;
                }
            }
            if (j == pageFrames.size()) {
                // Did not find place in pages. Replace last to be used next.
                // Sort by nextUsed.
                for (uint k = 0; k < pageFrames.size(); ++k) {
                    uint m;
                    for (m = i + 1; m < pagestring.size(); ++m) {
                        if (pageFrames[k].pageID == pagestring[m]) {
                            pageFrames[k].nextUsed = m;
                            m = pagestring.size() + 1;
                        }
                    }
                    if (m == pagestring.size()) {
                        pageFrames[k].nextUsed = 100000;
                    }
                }
                sort(pageFrames.begin(), pageFrames.end(), compare);
                pageFrames[0].pageID = pagestring[i];
                ++pageFaults;
            }
            // Update output values
            switch (i) {
                case 2000:
                // Update for 2000 pages.
                output.rateAt2000 = float(pageFaults) / float(i);
                break;
                case 4000:
                // Update for 4000 pages.
                output.rateAt4000 = float(pageFaults) / float(i);
                break;
                case 6000:
                // Update for 6000 pages.
                output.rateAt6000 = float(pageFaults) / float(i);
                break;
                case 8000:
                // Update for 8000 pages.
                output.rateAt8000 = float(pageFaults) / float(i);
                break;
                case 10000:
                // Update for 10000 pages.
                output.rateAt10000 = float(pageFaults) / float(i);
                break;
                default: break;
            }
        }
        output.totalPageFaults = pageFaults;
        return output;
    }

    bool compare(const PageFrame &i, const PageFrame &j) {
        return (i.nextUsed > j.nextUsed);
    }

}