#pragma once
#include <iostream>
using std::string, std::cout;


struct Node {
    char label;
    explicit Node(char& label) : label{label} {   }
    ~Node(){cout << "del:" << label << " ";}
    bool operator<(const struct Node& other) const { return this->label < other.label; }
    [[nodiscard]] char print() const { return label; }
};