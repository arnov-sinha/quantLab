#include <iostream>
#include <cstdlib>
#include "csvReader.h"
#include "tradeAnalysis.h"
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    
    ofstream of;
    of.open("output.csv");
    tradeAnalysis ta("input.csv");
    
    vector<string> s(ta.ip.symbol);
  
    sort(s.begin(),s.end());
    s.erase( unique( s.begin(), s.end() ), s.end() );
    for(auto elem : s){
        of<<elem<<",";
        of<<ta.maxTimeGap(elem);
        of<<",";
        of<<ta.maxTradePrice(elem);
        of<<",";
        of<<ta.totalTrade(elem);
        of<<",";
        of<<ta.weightedAveragePrice(elem);
        of<<"\n";
    }
    
    return 0;
}


