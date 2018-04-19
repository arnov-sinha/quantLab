#include <vector>
#include <climits>
#include "tradeAnalysis.h"
#include <algorithm>
#include <map>

tradeAnalysis::tradeAnalysis(string _fileName) {
    csvReader i(_fileName);
    ip = i;
}

tradeAnalysis::~tradeAnalysis(){
}

unsigned long long tradeAnalysis::maxTimeGap(string indices){
    typedef multimap<string, unsigned long long> MM;
    MM time(ip.timeStamp);
    typedef pair<string, unsigned long long> pairMM;
    pair<MM::iterator, MM::iterator> pairSet;
    
    pairSet = time.equal_range(indices);
    
    int maxGap = 0;
    unsigned long long one , two;
    
    for(MM::iterator it = pairSet.first; it != pairSet.second; ++it){
        one = it->second;
        break;
    }
        
    for(MM::iterator it = pairSet.first; it != pairSet.second; ++it){
        two = it->second;
        auto diff = two - one;
        maxGap = diff>maxGap ? diff : maxGap;
        one = two;
    }
    return maxGap;
}

int tradeAnalysis::maxTradePrice(string indices){
    typedef multimap<string, int> MM;
    MM tradePrice(ip.price);
    
    typedef pair<string, int> pairMM;
    pair<MM::iterator, MM::iterator> pairSet;
    
    pairSet = tradePrice.equal_range(indices);
    
    int maxPrice = INT_MIN;
    
    for(MM::iterator it = pairSet.first; it != pairSet.second; ++it)
        maxPrice = max(maxPrice,it->second);
    
    return maxPrice;
}

double tradeAnalysis::weightedAveragePrice(string indices){
    typedef multimap<string, int> MM;
    MM tradePrice(ip.price);
    MM qty(ip.quantity);
    
    typedef pair<string, int> pairMM;
    pair<MM::iterator, MM::iterator> pairSet1;
    pair<MM::iterator, MM::iterator> pairSet2;
    
    pairSet1 = tradePrice.equal_range(indices);
    pairSet2 = qty.equal_range(indices);
    
    double sum=0.0;
    vector<int> tp;
    vector<int> q;
    
    for(MM::iterator it = pairSet1.first; it != pairSet1.second; ++it)
        tp.push_back(it->second);
    
    for(MM::iterator it = pairSet2.first; it != pairSet2.second; ++it)
        q.push_back(it->second);
    
    for(int i = 0; i < q.size(); i++ ){
        sum += tp[i] * q[i];
    }

    return sum/q.size();
}

int tradeAnalysis::totalTrade(string indices){
    typedef multimap<string, int> MM;
    MM qty(ip.quantity);
    
    typedef pair<string, int> pairMM;
    pair<MM::iterator, MM::iterator> pairSet;
    
    pairSet = qty.equal_range(indices);
    
    int total = 0;
    
    for(MM::iterator it = pairSet.first; it != pairSet.second; ++it)
        total+=it->second;
    
    return total;
}
