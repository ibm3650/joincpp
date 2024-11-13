//
// Created by kandu on 13.11.2024.
//

#ifndef JOINCPP_JOIN_H
#define JOINCPP_JOIN_H

#include <string>
#include <span>
#include <type_traits>
#include "meta.h"
#include "stringify.h"

namespace joincpp {
    template<typename T>
    [[nodiscard]] constexpr std::string to_string(const T &value) {
        if constexpr (std::is_integral_v<T>) {
            return std::to_string(value);
        }
        std::string_view arg_name = stringify<T>{}(value);
        return {arg_name.begin(), arg_name.end()};
    }

    class separator {
    public:
        separator(const char *str, size_t length) : _sep(str, length) {}

        // Перегрузка для одиночного элемента (не контейнер)
        template<typename T>
        std::enable_if_t<!is_container_v<T>, std::string>
        join(const T &element) {
            return to_string(element);
        }

        // Перегрузка для контейнеров (std::vector, std::list и т.д.)
        template<typename T>
        std::enable_if_t<is_container_v<T>, std::string>
        join(const T &elements) {
            std::string s;
            for (const auto &element: elements) {
                s += to_string(element) + _sep;
            }
            if (!s.empty()) {
                s.erase(s.size() - _sep.size()); // Удаляем последний разделитель
            }
            return s;
        }

        // Перегрузка для массивов C-style (int arr[])
        template<typename T, size_t N>
        std::string join(T (&elements)[N]) {
            std::string s;
            for (const auto &element: elements) {
                s += to_string(element) + _sep;
            }
            if (!s.empty()) {
                s.erase(s.size() - _sep.size()); // Удаляем последний разделитель
            }
            return s;
        }

        // Перегрузка для std::initializer_list
        template<typename T>
        std::string join(std::initializer_list<T> elements) {
            std::string s;
            for (const auto &element: elements) {
                s += to_string(element) + _sep;
            }
            if (!s.empty()) {
                s.erase(s.size() - _sep.size()); // Удаляем последний разделитель
            }
            return s;
        }

        // Перегрузка для параметров с переменным числом аргументов
        template<typename First, typename... Types>
        std::enable_if_t<!is_container_v<First>, std::string>
        join(First first, Types... elements) {
            std::string s = to_string(first) + _sep;
            ((s += to_string(elements) + _sep), ...);
            if (!s.empty()) {
                s.erase(s.size() - _sep.size()); // Удаляем последний разделитель
            }
            return s;
        }

        //TODO: recursive join for nested containers
        //TODO: strings only join
    private:
        std::string _sep;
    };

    separator operator "" sep(const char *str, size_t length) {
        return {str, length};
    }
}

#endif //JOINCPP_JOIN_H
