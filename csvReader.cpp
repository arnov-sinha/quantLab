
#include <vector>

#include "csvReader.h"

using namespace std;

csvReader::csvReader(string fileName) {
    string temp[4];
    ifstream i(fileName);
    unsigned long long time;
    if(!i.is_open())
        cout<<"File cannot be opened";
    while(!i.eof()){
        
        getline(i,temp[0], ',');
        getline(i,temp[1], ',');
        getline(i,temp[2], ',');
        getline(i,temp[3], '\n');
        stringstream ss(temp[0]);
        ss>>time;
        timeStamp.insert(pair<string, unsigned long long>(temp[1], time));
        symbol.push_back(temp[1]);
        quantity.insert(pair<string, int>(temp[1], stoi(temp[2])));
        price.insert(pair<string, int>(temp[1], stoi(temp[3])));
    }
    i.close();
}

csvReader::csvReader() {
}

csvReader::~csvReader() {
}
