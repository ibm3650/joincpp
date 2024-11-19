//
// Created by kandu on 14.11.2024.
//
#include <gtest/gtest.h>
#include "joincpp/meta.h"
#include <vector>
#include <list>
#include <string>

TEST(IsContainerTest, PrimitiveTypes) {
    EXPECT_FALSE(is_container_v<int>);
    EXPECT_FALSE(is_container_v<double>);
    EXPECT_FALSE(is_container_v<char>);
}

TEST(IsContainerTest, StandardContainers) {
    EXPECT_TRUE(is_container_v<std::vector<int>>);
    EXPECT_TRUE(is_container_v<std::list<std::string>>);
    //FIXME: std::string can be treated as a sequence container
    EXPECT_TRUE(is_container_v<std::string>);
}

TEST(IsContainerTest, CustomTypes) {
    struct NonContainer {
    };
    EXPECT_FALSE(is_container_v<NonContainer>);

    struct CustomContainer {
        int *begin() { return nullptr; }

        int *end() { return nullptr; }
    };
    EXPECT_TRUE(is_container_v<CustomContainer>);
}


TEST(IsArrayTest, CompatibleTypes) {
    char arr[] = "test";
    EXPECT_TRUE((is_array_t<char[1], char>::value));
    EXPECT_TRUE((is_array_t<decltype(arr), char>::value));
    EXPECT_FALSE((is_array_t<char *, char>::value));
}