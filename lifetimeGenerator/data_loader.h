#ifndef DATA_LOADER_H
#define DATA_LOADER_H


#include <vector>
#include <string>

struct DataPoint {
    double x;
    double y;
};

std::vector<DataPoint> loadDataFromFile(const std::string& filename);


#endif // DATA_LOADER_H
