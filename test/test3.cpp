//
// Created by kandu on 14.11.2024.
//

#include <gtest/gtest.h>
#include "joincpp/join.h"
#include <string>
#include <vector>
#include <list>

using namespace joincpp;
// Test cases for to_string function
TEST(ToStringTest, BasicTypes) {
    EXPECT_EQ(to_string(10), "10");
    EXPECT_EQ(to_string(3.14), "3.14");
    EXPECT_EQ(to_string('x'), "x");
}

TEST(ToStringTest, StdString) {
    EXPECT_EQ(to_string(std::string("hello")), "hello");
    EXPECT_EQ(to_string("world"), "world");
}

TEST(ToStringTest, ContainerTypes) {
    std::vector<int> vec = {1, 2, 3};
    EXPECT_EQ(to_string(vec), "1, 2, 3");
}

// Test cases for separator join method
TEST(SeparatorTest, JoinSingleElement) {
    separator sep(", ");
    EXPECT_EQ(sep.join(42), "42");
    EXPECT_EQ(sep.join("test"), "test");
}

TEST(SeparatorTest, JoinMultipleElements) {
    separator sep(", ");
    EXPECT_EQ(sep.join(1, 2, 3), "1, 2, 3");
    EXPECT_EQ(sep.join("a", "b", "c"), "a, b, c");
}

TEST(SeparatorTest, JoinContainer) {
    separator sep(", ");
    std::vector<int> vec = {4, 5, 6};
    EXPECT_EQ(sep.join(vec), "4, 5, 6");

    std::list<std::string> lst = {"x", "y", "z"};
    EXPECT_EQ(sep.join(lst), "x, y, z");
}
