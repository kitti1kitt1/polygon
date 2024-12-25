#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // Для std::max

class Solution {
public:
    int longestValidParentheses(const std::string& s) {
        std::stack<int> indices; // Стек для хранения индексов
        indices.push(-1); // Добавляем -1 для удобства расчёта длины
        int maxLength = 0; // Переменная для хранения максимальной длины

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                indices.push(i); // Открывающая скобка: сохраняем индекс
            }
            else {
                indices.pop(); // Закрывающая скобка: убираем верхний элемент
                if (indices.empty()) {
                    indices.push(i); // Если стек пуст, добавляем текущий индекс
                }
                else {
                    maxLength = std::max(maxLength, i - indices.top()); // Вычисляем длину
                }
            }
        }
        return maxLength; // Возвращаем максимальную длину
    }
};

// Пример использования
int main() {
    Solution solution;
    std::string s = "(()))())("; // Пример строки
    int result = solution.longestValidParentheses(s);
    std::cout << "Longest valid parentheses length: " << result << std::endl;
    return 0;
}
