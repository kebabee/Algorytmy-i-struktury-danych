#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <iterator>
#include <set>
#include "template.h"

int main() {
    //a)
    std::vector<int> vec1(10);
    std::vector<int> vec2(10);

    //b)
    std::iota(vec1.begin(), vec1.end(), 0);
    std::cout << "wektor 1\niota: " << vec1 << "\n";

    //c)
    auto sum = std::accumulate(vec1.begin(), vec1.end(), 0);
    std::cout << "accumulate: " << sum << "\n";

    //d)
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) { return x * x; });
    std::cout << "transform: " << vec1 << "\n\n";

    //e)
    std::generate(vec2.begin(), vec2.end(), []() { return std::rand() % 15; });
    std::cout << "wektor 2\ngenerate: " << vec2 << "\n";

    //f)
    auto max = *std::max_element(vec2.begin(), vec2.end());
    std::cout << "max_element: " << max << "\n";

    //g)
    std::sort(vec2.begin(), vec2.end());
    std::cout << "sort: " << vec2 << "\n";

    //h)
    auto uni = std::unique(vec2.begin(), vec2.end());
    std::cout << "unique: " << vec2 << "\n";

    //i)
    vec2.erase(uni, vec2.end());
    std::cout << "erase: " << vec2 << "\n\n";

    //j)
    std::vector<int> vec3(2);
    std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
    std::cout << "wektor 3\nset_intersection: " << vec3 << "\n";

    return 0;
}