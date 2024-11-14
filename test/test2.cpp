//
// Created by kandu on 14.11.2024.
//
#include <gtest/gtest.h>
#include "joincpp/stringify.h"
#include <string>
#include <vector>

// Test cases for function_signature

TEST(FunctionSignatureTest, BasicTypes) {
//    EXPECT_EQ(function_signature<int>(), "int");
//    EXPECT_EQ(function_signature<double>(), "double");
//    EXPECT_EQ(function_signature<std::string>(), "std::string");
}

TEST(FunctionSignatureTest, TemplateTypes) {
    //EXPECT_EQ(function_signature<std::vector<int>>(), "std::vector<int>");
  //  EXPECT_EQ(function_signature<std::pair<int, double>>(), "std::pair<int, double>");
}

// Test cases for stringify class
TEST(StringifyTest, PrimitiveTypes) {
//    EXPECT_EQ(stringify<int>{}(42), "42");
//    EXPECT_EQ(stringify<double>{}(3.14), "3.14");
//    EXPECT_EQ(stringify<char>{}('a'), "a");
}

TEST(StringifyTest, StdString) {
  //  EXPECT_EQ(stringify<std::string>::to_string("hello"), "hello");
  //  EXPECT_EQ(stringify<const char*>::to_string("world"), "world");
}

TEST(StringifyTest, ContainerTypes) {
    //std::vector<int> vec = {1, 2, 3};
//    EXPECT_EQ(stringify<std::vector<int>>::to_string(vec), "[1, 2, 3]");
}
