//
// Created by kandu on 13.11.2024.
//

#ifndef JOINCPP_STRINGIFY_H
#define JOINCPP_STRINGIFY_H

#include <string>

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


//Шаблонный класс для преобразования типа в строку.
// Подразумевается, что для каждого необходимого типа будет создана специализация данного класса
template<typename T>
struct stringify {
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
