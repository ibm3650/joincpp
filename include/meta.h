//
// Created by kandu on 13.11.2024.
//

#ifndef JOINCPP_META_H
#define JOINCPP_META_H


#include <utility>

// Проверка, является ли тип контейнером. value == false. Для этого наследуется от std::false_type
//Второй параметр шаблона нужен для SFINAE
template<typename T, typename = void>
struct is_container : std::false_type {
};

// Проверка, является ли тип контейнером. value == true. Для этого наследуется от std::true_type
//Попытка вызвать метод begin() у типа T. Если это не удалось, то специализация не сработает
//и не будет ошибкой так как это SFINAE
template<typename T>
struct is_container<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {
};

template<typename T>
constexpr bool is_container_v = is_container<T>::value;
#endif //JOINCPP_META_H
