#include <iostream>
#include <vector>
#include "template.h"

int main() {
    std::vector<double> vec1 = {1.0, 5.1, 132.99};
    std::vector<char> vec2 = {'a', 'x', '9', '?', '#'};
    std::vector<int> vec3 = {5, 149, 124957};

    std::cout << "wektor 1: " << vec1 << "\n";
    std::cout << "wektor 2: " << vec2 << "\n";
    std::cout << "wektor 3: " << vec3 << "\n";

    return 0;
}