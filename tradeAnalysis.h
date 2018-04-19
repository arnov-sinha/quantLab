#include <string>
#include "csvReader.h"

using namespace std;

#ifndef TRADEANALYSIS_H
#define TRADEANALYSIS_H

class tradeAnalysis {
public:
    
    tradeAnalysis(string _fileName);
    virtual ~tradeAnalysis();
    
    unsigned long long maxTimeGap(string indices);
    int totalTrade(string indices);
    int maxTradePrice(string indices);
    double weightedAveragePrice(string indices);
    
    csvReader ip;

};

#endif /* TRADEANALYSIS_H */

