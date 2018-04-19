#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class csvReader {
public:
    csvReader();
    csvReader(string fileName);
    virtual ~csvReader();
    
public:
    
    vector<string> symbol;
    multimap<string, unsigned long long> timeStamp;
    multimap<string, int> quantity;
    multimap<string, int> price;
    
    
    
};

#endif /* CSVREADER_H */
