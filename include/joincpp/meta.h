//
// Created by kandu on 13.11.2024.
//

#ifndef JOINCPP_META_H
#define JOINCPP_META_H


#include <utility>

/**
 * @brief Шаблонная структура для проверки, является ли тип контейнером
 * @details Проверка, является ли тип контейнером. value == false. Для этого наследуется от std::false_type
 * Второй параметр шаблона нужен для SFINAE
 * @tparam T Тип, который нужно проверить
 */
template<typename T, typename = void>
struct is_container : std::false_type {
};

// Проверка, является ли тип контейнером. value == true. Для этого наследуется от std::true_type
//Попытка вызвать метод begin() у типа T. Если это не удалось, то специализация не сработает
//и не будет ошибкой так как это SFINAE
/**
 * @brief Шаблонная структура для проверки, является ли тип контейнером
 * @details Проверка, является ли тип контейнером. value == true. Для этого наследуется от std::true_type
 * Попытка вызвать метод begin() у типа T. Если это не удалось, то специализация не сработает
 * и не будет ошибкой так как это SFINAE
 * @tparam T Тип, который нужно проверить
 */
template<typename T>
struct is_container<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {
};

/**
 * @brief Шаблонная переменная для проверки, является ли тип контейнером
 * @details Адаптер для непосредственного получения boolean значения из шаблонной структуры is_container
 * @tparam T Тип, который нужно проверить
 */
template<typename T>
constexpr bool is_container_v = is_container<T>::value;


template<typename T, typename = void>
struct is_array_t : std::false_type {
};

template<typename T, size_t N>
struct is_array_t<T[N], T> : std::true_type {
};

template<typename T, typename U>
constexpr bool is_array_t_v = is_array_t<T, U>::value;
#endif //JOINCPP_META_H
