#include <iostream>
#include <Windows.h>

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw std::exception("Вы ввели слово запретной длины! До свидания");
    }
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);    

    try
    {
        int userNum = 0;
        std::string userText;

        std::cout << "Введите запретную длину: ";
        std::cin >> userNum;

        while (true) {

            std::cout << "Введите слово: ";
            std::cin >> userText;

            function(userText, userNum);

            std::cout << "Длина слова \"" << userText << "\" равна " << userText.length() << std::endl;
            userText.clear();
        }
    }
    catch (const std::exception& bad_length)
    {
        std::cout << bad_length.what() << std::endl;
    }
}