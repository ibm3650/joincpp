//
// Created by kandu on 13.11.2024.
//

#ifndef JOINCPP_STRINGIFY_H
#define JOINCPP_STRINGIFY_H

#include <string>

/**
 * @brief Функция получения сигнатуры функции
 * @details Функция возвращает строковое представление сигнатуры функции.
 * Применяются соответсвующие директивы препроцессора. Если компилятор не поддерживает соответствующую директиву,
 * то возвращается пустая строка.
 * @tparam T Тип функции
 * @return Строковое представление сигнатуры функции
 */
template<typename T>
[[nodiscard]] constexpr std::string_view function_signature() {
#if defined(__clang__) || defined(__GNUC__)
    return __PRETTY_FUNCTION__;
#elif defined(_MSC_VER)
    return __FUNCSIG__;
#else
    return "";
#endif
}


/**
 * @brief Шаблонный класс для преобразования типа в строку.
 * @details Подразумевается, что для каждого необходимого типа будет создана специализация данного класса.
 * @tparam T Тип, который нужно преобразовать в строку
 */
template<typename T>
struct stringify {
    /**
     * @brief Оператор вызова для преобразования типа в строку
     * @details Возвращает строковое представление типа T.
     * @param[in] value Значение, которое нужно преобразовать в строку
     * @return Строковое представление типа T
     */
    [[nodiscard]] constexpr std::string_view operator()(const T & /*value*/) const noexcept {
        constexpr std::string_view sign = function_signature<T>();
        constexpr size_t start = sign.find("function_signature");
        if constexpr (start != std::string_view::npos) {
            return sign.substr(start + 19, sign.size() - 7 - 19 - start);
        } else {
            return "unknown";
        }
    }
};


#endif //JOINCPP_STRINGIFY_H
