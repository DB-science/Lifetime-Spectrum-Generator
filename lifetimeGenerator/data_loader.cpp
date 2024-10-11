#include "data_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<DataPoint> loadDataFromFile(const std::string& filename) {
    std::vector<DataPoint> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        DataPoint point;
        if (iss >> point.x >> point.y) {
            data.push_back(point);
        }
    }

    file.close();
    return data;
}
