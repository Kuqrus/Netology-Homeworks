#include <iostream>
#define MODE 1

#ifndef MODE
#error Need to define constant "MODE"
#endif // !MODE

#if MODE == 1
int add(int num1, int num2) {
    return num1 + num2;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Работаю в боевом режиме" << std::endl;

    int userNum1 = 0, userNum2 = 0;
    std::cout << "Введите первое число: ";
    std::cin >> userNum1;

    std::cout << "Введите второе число: ";
    std::cin >> userNum2;

    std::cout << "Результат сложения: " << add(userNum1, userNum2);

#elif MODE == 0
int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Работаю в режиме тренировки" << std::endl;

#else 
int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Неизвестный режим. Завершение работы" << std::endl;

#endif

}
