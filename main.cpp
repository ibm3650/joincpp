#include <iostream>
#include <vector>
#include "join.h"



using namespace joincpp;

int main() {
    std::vector<int> v0 = {1, 2, 3};
    const auto v0s = ","sep.join(v0);
    int v1[] = {1, 2, 3};
    const auto v1s = ","sep.join(v1);
    const auto v2 = {1, 2, 3};
    const auto v2s = ","sep.join(v2);
    const auto v3s = ","sep.join(1, 2, 3, 4, v1, v0);
    const int* v4 = v1;
    const auto v4s = ","sep.join(std::span{v4, std::size(v1)});
    const auto v5s = ","sep.join(1);
    std::cout << "vector: " <<  v0s << std::endl;
    std::cout << "C array: " << v1s << std::endl;
    std::cout << "initializer_list: " << v2s << std::endl;
    std::cout << "Template pack: " << v3s << std::endl;
    std::cout << "Pointer: " << v4s << std::endl;
    std::cout << "Single value: " << v5s << std::endl;
    return 0;
}
