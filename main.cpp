#include <windows.h>
#include <iostream>
#include <limits>
#include <cmath>


// Функция проверки ввода. Возвращает true, если ввод успешен.
bool readNumber(int& value) {
    if (std::cin >> value) {
        return true;
    }

    // Очистка состояния потока и сброс ошибочного ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}

// Ввод двух чисел с обработкой ошибок
void inputNumbers(int& first, int& second) {
    while (true) {
        std::cout << "Введите первое число: ";
        if (readNumber(first)) {
            break;
        }
        std::cout << "Ошибка: нужно ввести число, а не строку. Попробуйте снова.\n";
    }

    while (true) {
        std::cout << "Введите второе число: ";
        if (readNumber(second)) {
            break;
        }
        std::cout << "Ошибка: нужно ввести число, а не строку. Попробуйте снова.\n";
    }
}

void inputNum(int& first) {
    while (true) {
        std::cout << "Введите число: ";
        if (readNumber(first)) {
            break;
        }
        std::cout << "Ошибка: нужно ввести число, а не строку. Попробуйте снова.\n";
    }
}

// Вывод меню и получение выбора пользователя
int showMenu() {
    std::cout << "\n=== Калькулятор ===\n";
    std::cout << "1 - Сложение\n";
    std::cout << "2 - Вычитание\n";
    std::cout << "3 - Умножение\n";
    std::cout << "4 - Деление\n";
    std::cout << "5 - Квадратный корень\n";
    std::cout << "6 - Натуральный логарифм\n";
    std::cout << "0 - Выход из калькулятора\n";
    std::cout << "Выберите операцию: ";

    int choice;
    while (true) {
        if (readNumber(choice)) {

            if (choice >= 0 && choice <= 6) {
                return choice;
            }
            std::cout << "Неверный выбор. Введите число от 0 до 6.\n";
        } else {
            std::cout << "Ошибка ввода. Попробуйте снова.\n";
        }
    }
}


void calculator() {
    while (true) {
        int choice = showMenu();

        if (choice == 0) {
            std::cout << "Выход из калькулятора.\n";
            break;
        }
        if (choice == 5) {
            int third;
            inputNum(third);
            if (third > 0){
                std::cout << "Результат (sqrt): " << std::sqrt(third) << "\n";
            }
            else {
                std::cout << "Ошибка: корень из отрицательного числа не определён в вещественных числах.\n";
            } 
        }
        
        if (choice == 6) {
            int third;
            inputNum(third);
            if (third > 0) {
                std::cout << "Результат (ln): " << std::log(third) << "\n";
            }
            else {
                std::cout << "Ошибка: логарифм определён только для положительных чисел.\n";
            }
        }

        int first, second;

        inputNumbers(first, second);

        switch (choice) {
            case 1:
                std::cout << "Результат: " << first + second << "\n";
                break;
            case 2:
                std::cout << "Результат: " << first - second << "\n";
                break;
            case 3:
                std::cout << "Результат: " << first * second << "\n";
                break;
            case 4:
                if (second == 0) {
                    std::cout << "Ошибка: на ноль делить нельзя.\n";
                } else {
                    std::cout << "Результат: " << first / second << "\n";
                }
                break;
            default:
                std::cout << "Неверная операция.\n";
                break;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); 
    calculator();
    return 0;
}
