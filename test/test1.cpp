//
// Created by kandu on 14.11.2024.
//
#include <gtest/gtest.h>
#include "joincpp/meta.h"
#include <vector>
#include <list>
#include <string>

// Test cases for is_container and is_container_v

TEST(IsContainerTest, PrimitiveTypes) {
    // Primitive types like int, double should not be considered containers
    EXPECT_FALSE(is_container_v<int>);
    EXPECT_FALSE(is_container_v<double>);
    EXPECT_FALSE(is_container_v<char>);
}

TEST(IsContainerTest, StandardContainers) {
    // Standard containers should be recognized as containers
    EXPECT_TRUE(is_container_v<std::vector<int>>);
    EXPECT_TRUE(is_container_v<std::list<std::string>>);
    EXPECT_TRUE(is_container_v<std::string>);  // std::string can be treated as a sequence container
}

TEST(IsContainerTest, CustomTypes) {
    // A custom type without begin/end should not be recognized as a container
    struct NonContainer {
    };
    EXPECT_FALSE(is_container_v<NonContainer>);

    // A custom type with begin/end should be recognized as a container
    struct CustomContainer {
        int *begin() { return nullptr; }

        int *end() { return nullptr; }
    };
    EXPECT_TRUE(is_container_v<CustomContainer>);
}


TEST(IsArrayTest, CompatibleTypes){
    char arr[] = "test";
    EXPECT_TRUE((is_array_t<char[1], char>::value));
    EXPECT_TRUE((is_array_t<decltype(arr), char>::value));
    EXPECT_FALSE((is_array_t<char*, char>::value));
}