#include <iostream>
#include <vector>
#include <format>
#include "joincpp/join.h"

using namespace joincpp;

struct float_number {
    uint8_t _sign;
    size_t _exp;
    size_t _mantissa;
};


template<>
struct stringify<float_number> {
    std::string operator()(const float_number &value) const noexcept {
        return std::format("float_number{{{}, {}, {}}}", value._sign, value._exp, value._mantissa);
    }
};


int main() {
    float_number arr[] = {{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};
    const std::string output = "| |"sep.join(arr);
    std::cout << "User defined formatting: " << output << std::endl;
    return 0;
}