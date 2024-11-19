# joincpp

---

<p align="center">A powerful C++ library that implements join functionality.
Supports any data types and provides a simple, easy-to-understand interface.</p>
<p align="center">
	<img src="https://img.shields.io/github/languages/top/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/languages/count/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/license/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/stars/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/issues/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/last-commit/ibm3650/joincpp" alt="">
</p>

> [!TIP] 
> The library is under development, any improvements, additions, and collaborations are welcome.

joincpp is a C++ library that allows you to concatenate variables into a string with a delimiter.
A key feature of this library is its support for user-defined data types, making it suitable for use in any project.
In essence, it replicates the functionality of Python's `join` function.
You can literally do the following, for example:
```cpp
","sep.join(2.3, user_defined_class, "string", 3);
```
And it will work!
Data types can even vary within a single `join` call. A wide range of overloads is supported, allowing the use of arrays, vectors, and other types as arguments.
---


## Key Features
The library stands out favorably from its analogues due to the following features:
- Support for user-defined data types
- Simple and easy-to-understand interface
- A wide variety of overloads
- Doxygen documentation
- C++17 compatibility
- CMake support
- Header-only implementation

## Getting Started

1. Clone the repository

```bash
git clone https://github.com/ibm3650/joincpp.git
```

2. Include the library in your project using CMake

```cmake
target_link_libraries(${PROJECT_NAME} PRIVATE joincpp)
```

3. Declare the  header in your code

```cpp
#include "joincpp/join.h"
```

4. Additional resources
- You can explore [examples in corresponding folder](https://github.com/ibm3650/joincpp/tree/main/examples), 
- for a quick start. To build the examples, execute:
```bash
cmake joincpp -DBUILD_EXAMPLES=ON
make
./example1 && ./example2
```

- To build and run the tests, execute:
```bash
cmake joincpp -DBUILD_TESTS=ON
make
./test/joincpp_test
```

## Examples
<details>
<summary>Example of using with basic types</summary>

```cpp
    std::vector<int> v0 = {1, 2, 3};
    const std::string v0s = ","sep.join(v0);
    
    int v1[] = {1, 2, 3};
    const std::string v1s = ","sep.join(v1);
    
    const auto v2 = {1, 2, 3};
    const std::string v2s = ","sep.join(v2);
    
    const std::string v3s = ","sep.join(1, 2, 3, 4, v1, v0);
    
    const int* v4 = v1;
    const std::string v4s = ","sep.join(std::span{v4, std::size(v1)});
    
    const std::string v5s = ","sep.join(1);
    
    std::cout << "vector: " <<  v0s << std::endl;
    std::cout << "C array: " << v1s << std::endl;
    std::cout << "initializer_list: " << v2s << std::endl;
    std::cout << "Template pack: " << v3s << std::endl;
    std::cout << "Pointer: " << v4s << std::endl;
    std::cout << "Single value: " << v5s << std::endl;
```
</details>

<details>
<summary>Example with user-defined types</summary>

```cpp

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
float_number arr[] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
const std::string output = "| |"sep.join(arr);
std::cout << "User defined formatting: " << output << std::endl;
return 0;
}

```

</details>

## Architecture
Repository contains the following folders:
- `include` - include files of the library
- `test` - tests of the library
- `docs` - documentation of the library
- `examples` - examples of using the library

## Contributing
The library is under development, any improvements, additions, and collaborations are welcome.

## Testing
For testing, the Google Test framework is used. The source code for the tests is located in the test directory.
The tests aim to improve code quality and enhance fault tolerance.
To execute the tests, simply run the binary file.
([Explore more details in the article](https://github.com/ibm3650/joincpp/tree/dev?tab=readme-ov-file#getting-started))


## Copyright
joincpp is released under the [MIT](https://github.com/ibm3650/joincpp/blob/dev/LICENSE).

Copyright © 2024 Kanduba Nikita. All rights reversed.