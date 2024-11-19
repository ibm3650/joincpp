# joincpp

---

<p align="center">Мощная C++ библиотека, реализующая функционал join. Любые типы данных. Простой и понятный интерфейс</p>
<p align="center">
	<img src="https://img.shields.io/github/languages/top/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/languages/count/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/license/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/stars/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/issues/ibm3650/joincpp" alt="">
	<img src="https://img.shields.io/github/last-commit/ibm3650/joincpp" alt="">
</p>

> [!TIP] 
> Библиотека развивается, любые улучшения, дополнения и коллаборации приветствуются


joincpp - это библиотека для C++, которая позволяет производить конкатенацию переменных в строку с разделителем.
Отличительной чертой библиотеки является поддержка пользовательских типов данных, что позволяет использовать ее в любом проекте.
Фактически, позволяет сделать то же самое, что и функция `join` в Python.
Вы буквально можете сделать, например:
```cpp 
    ","sep.join(2.3, user_defined_class, "string", 3) ;
``` 
И это сработает!
Данны могут быть даже разных типов для одного вызова join. Поддерживается широкий список перегрузок.
Например, использование массивов или векторов в качестве аргументов функции join.
---


## Key Features
Библиотеку выгодно отличают на фоне аналогов следующие ключевые особенности:
- Поддержка пользовательских типов данных
- Простой и понятный интерфейс
- Поддержка широкого списка перегрузок
- Doxygen документация
- Поддержка C++17
- Поддержка CMake
- Библиотека является header-only

## Getting Started

1. Клонируйте репозиторий 

```bash
git clone https://github.com/ibm3650/joincpp.git
```

2. Подключите с помощью cmake

```cmake
target_link_libraries(${PROJECT_NAME} PRIVATE joincpp)
```

3. Укажите файл заголовка

```cpp
#include "joincpp/join.h"
```

4.
- Также можете ознакомиться с [примерами в соответсвующее папке](https://github.com/ibm3650/joincpp/tree/main/examples), 
для быстрого старта. Для сборки выполните
```bash
cmake joincpp -DBUILD_EXAMPLES=ON
make
./example1 && ./example2
```

- Для сборки тестов выполните
```bash
cmake joincpp -DBUILD_TESTS=ON
make
./test/joincpp_test
```

## Examples
<details>
<summary>Пример базового использования с различными данными</summary>

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
<summary>Пример применения с пользовательскими типами</summary>

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
Репозиторий содержит следующие директории:
- `include` - заголовочные файлы библиотеки
- `src` - исходный код библиотеки
- `test` - тесты библиотеки
- `docs` - документация библиотеки
- `examples` - примеры использования библиотеки

## Contributing
Библиотека развивается, любые улучшения, дополнения и коллаборации приветствуются

## Testing
Для тестов используется фреймворк Google.Tests. Исходный код тестов находится в директории test.
Тесты нацелены на повышение качества кода и повышение отказоустойчивости.
Для запуска достаточно запустить исполняемый файл после сборки
([Ознакомьтесь детальнее с пунктом 4](https://github.com/ibm3650/joincpp/tree/dev?tab=readme-ov-file#getting-started))


## Copyright
joincpp is released under the [MIT](https://github.com/ibm3650/joincpp/blob/dev/LICENSE).

Copyright © 2024 Kanduba Nikita. All rights reversed.