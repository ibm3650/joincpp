#include <iostream>
#include <vector>
#include "joincpp/join.h"

using namespace joincpp;
//TODO: тест пользовательского форматера
int main() {

    std::vector<int> v0 = {1, 2, 3};
    const std::string v0s = ","sep.join(v0);

    int v1[] = {1, 2, 3};
    const std::string v1s = ","sep.join(v1);

    const auto v2 = {1, 2, 3};
    const std::string v2s = ","sep.join(v2);

    const std::string v3s = ","sep.join(1, 2, 3, 4, v1, v0);

    const int *v4 = v1;
    const std::string v4s = ","sep.join(std::span{v4, std::size(v1)});

    const std::string v5s = ","sep.join(1);

    std::cout << "vector: " << v0s << std::endl;
    std::cout << "C array: " << v1s << std::endl;
    std::cout << "initializer_list: " << v2s << std::endl;
    std::cout << "Template pack: " << v3s << std::endl;
    std::cout << "Pointer: " << v4s << std::endl;
    std::cout << "Single value: " << v5s << std::endl;
    return 0;
}
