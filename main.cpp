
#include <iostream>
#include <cstdlib>
#include "csvReader.h"
#include "tradeAnalysis.h"
#include <algorithm>
#include <vector>

using namespace std;


template <class It, class T>
  int binarysearch (It first, It last, const T& val)
{
    It c = first;
  first = lower_bound(first,last,val);
  if(first!=last && !(val<*first))
      return first-c;
}

int main(int argc, char** argv) {
    
    ofstream of;
    of.open("output.csv");
    tradeAnalysis ta("input.csv");
    
    vector<string> s(ta.ip.symbol);
    sort(s.begin(),s.end());
    s.erase( unique( s.begin(), s.end() ), s.end() ); 
    for(auto elem : s){
        of<<elem<<",";
        of<<ta.maxTimeGap(elem)<<",";
        of<<ta.totalTrade(elem)<<",";
        of<<ta.weightedAveragePrice(elem)<<",";
        of<<ta.maxTradePrice(elem)<<"\n";
    }
    
    
    
    return 0;
}
