#ifndef JOINCPP_JOIN_H
#define JOINCPP_JOIN_H

#include <string>
#include <span>
#include <type_traits>
#include "meta.h"
#include "stringify.h"

namespace joincpp {
    /**
     * @brief Функция преобразования значения в строку
     * @details Если тип T является интегральным, преобразование осуществляется с помощью std::to_string.
     * В противном случае используется специализация stringify<T> для данного типа.
     * Если данная специализация отсутствует, то будет получено имя данного типа в строковом представлении.
     * @tparam T
     * @param[in] value Значение, которое нужно преобразовать в строку
     * @return Строковое представление значения
     */
    template<typename T>
    [[nodiscard]] constexpr std::string to_string(const T &value) {
        if constexpr (std::is_integral_v<T>) {
            return std::to_string(value);
        }
        std::string_view arg_name = stringify<T>{}(value);
        return {arg_name.begin(), arg_name.end()};
    }

    //TODO: recursive join for nested containers
    //TODO: join for containers of strings
    /**
     * @brief Класс-разделитель
     * @details Класс, предназначенный для объединения элементов в строку с разделителем
     */
    class separator {
    public:
        separator(const char *str, size_t length) : _sep(str, length) {}

        /**
         * @brief Функция объединения элементов в строку
         * @details Перегрузка для одного элемента. Фактически, просто преобразует элемент в строку.
         * @tparam T Тип элемента
         * @param[in] element Элемент который нужно объединить нужно объединить
         * @return Строковое представление элемента
         */
        template<typename T>
        std::enable_if_t<!is_container_v<T>, std::string>
        join(const T &element) {
            return to_string(element);
        }

        /**
         * @brief Функция объединения элементов в строку
         * @details Перегрузка для контейнеров. Работает с контейнерами стандартной библиотеки, а также классами,
         * имеющими методы begin() и end().
         * @tparam T Тип контейнера
         * @param[in] elements Контейнер элементов, которые нужно объединить
         * @return Объединение элементов в строковом представлении, разделенных разделителем
         */
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


        /**
         * @brief Функция объединения элементов в строку
         * @details Перегрузка для массивов C-style фиксированного размера
         * @tparam T Тип элементов
         * @tparam N Размер массива
         * @param[in] elements Массив элементов, которые нужно объединить
         * @return Объединение элементов в строковом представлении, разделенных разделителем
         */
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

        /**
         * @brief Функция объединения элементов в строку
         * @details Перегрузка для std::initializer_list
         * @tparam T Тип элементов
         * @param[in] elements Список элементов, которые нужно объединить
         * @return Объединение элементов в строковом представлении, разделенных разделителем
         */
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

        /**
         * @brief Функция объединения элементов в строку
         * @details Перегрузка для переменного числа аргументов. Применяется для произвольного числа элементов в шаблоне
         * @tparam First Тип первого элемента
         * @tparam Types Типы остальных элементов
         * @param[in] first Первый элемент
         * @param[in] elements Остальные элементы
         * @return Объединение элементов в строковом представлении, разделенных разделителем
         */
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



        /**
        * @brief Функция объединения элементов в строку
        * @details Перегрузка для std::span. Применяется для указателей и массивов C-style переменного размера,
        * где пользователь его явно его указал.
        * @tparam T Тип элементов
        * @param[in] elements std::span элементов, которые нужно объединить
        * @return Объединение элементов в строковом представлении, разделенных разделителем
        */
    private:
        std::string _sep; /**< Разделитель */
    };

    /**
     * @brief Литерал для создания объекта separator
     * @details Позволяет создать объект separator с помощью литерала.
     * @param[in] str Строка-разделитель
     * @param[in] length Длина строки-разделителя
     * @return Объект separator
     */
    separator operator "" sep(const char *str, size_t length) {
        return {str, length};
    }
}

#endif //JOINCPP_JOIN_H
