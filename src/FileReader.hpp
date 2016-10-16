#pragma once

#include <fstream>

namespace bwgl {
    bool TryReadFromFile(std::string filename, std::string &out);
}

inline bool bwgl::TryReadFromFile(std::string filename, std::string &out) {
    std::ifstream ifs(filename.c_str());

    if (ifs.is_open()) {
        std::string s;
        while (std::getline(ifs, s)) {
            out += s + "\n";
        }
    } else {
        return false;
    }

    ifs.close();
    return true;
}