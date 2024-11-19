//
// Created by kandu on 14.11.2024.
//
#include <gtest/gtest.h>
#include "joincpp/stringify.h"
#include <string>
#include <vector>


TEST(StringifyTest, NonDeclaredFormatter) {
    std::vector var = {42.0};
    EXPECT_EQ(stringify<decltype(var)>{}(var), "class std::vector<double,class std::allocator<double> >>(void)");
}

template<>
struct stringify<std::vector<int>>{
    std::string operator()(const std::vector<int> &value) const noexcept {
        return "std::vector<int>";
    }
};
TEST(StringifyTest, DeclaredFormatter) {
    std::vector var = {42};
    EXPECT_EQ(stringify<decltype(var)>{}(var), "std::vector<int>");
}


