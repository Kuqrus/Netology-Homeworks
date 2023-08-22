#include <iostream>

// 6-1

//int simple_string_hash(std::string str) {
//    size_t size = str.size();
//    int hash = 0;
//    for (int i = 0; i < size; i++) {
//        hash += static_cast<int>(str[i]);
//    }
//
//    return hash;
//}
//
//void counting_hash() {
//    std::string userInput = "";
//    do
//    {
//        std::cout << "Введите строку: ";
//        std::cin >> userInput;
//
//        std::cout << "Наивный хэш строки " << userInput << ": " << simple_string_hash(userInput) << std::endl;
//    } while (userInput != "exit");
//}

// 6-2

//int power(int num, int power_of) {
//    if (power_of == 0) {
//        return 1;
//    }
//    if (power_of == 1) {
//        return num;
//    }
//    return num * power(num, power_of - 1);
//}
//
//int real_string_hash(std::string str, int p, int n) {
//    size_t size = str.size();
//    int hash = 0;
//
//    for (int i = 0; i < size; i++) {
//        hash += static_cast<int>(str[i]) * power(p, i);
//    }
//
//    hash = hash % n;
//
//    return hash;
//}
//
//void counting_real_hash() {
//    std::string userInput = "";
//    int p = 0, n = 0;
//    std::cout << "Введите значение p: ";
//    std::cin >> p;
//
//    std::cout << "Введите значение n: ";
//    std::cin >> n;
//
//    do
//    {
//        std::cout << "Введите строку: ";
//        std::cin >> userInput;
//
//        std::cout << "Наивный хэш строки " << userInput << ": " << real_string_hash(userInput, p, n) << std::endl;
//    } while (userInput != "exit");
//}

// 6-3

int power(int num, int power_of) {
    if (power_of == 0) {
        return 1;
    }
    if (power_of == 1) {
        return num;
    }
    return num * power(num, power_of - 1);
}

int hash(std::string str) {
    int hash = 0;

    for (int i = 0; i < str.size(); i++) {
        hash += static_cast<int>(str[i]) * power(29, i) % 1000;
    }
    return hash;    
}

int find_substring_light_rabin_karp(std::string str, int hashStr2, int sizeStr2, int startPoint) {
    int hash = 0;
    int x = startPoint;

    for (int i = 0; i < sizeStr2; i++) {
        hash += static_cast<int>(str[x++]) * power(29, i) % 1000;
    }

    if (hash == hashStr2) {
        return startPoint;
    }
    else return -1;
}

void test() {
    std::string str1, str2;
    int sym = 0;

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str1;
    int sizeStr1 = str1.size();

    do
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> str2;
        int sizeStr2 = str2.size();
        int hashStr2 = hash(str2);

        int index = 0;
        for (int i = 0; i < str1.size() - sizeStr2; i++) {
            index = find_substring_light_rabin_karp(str1, hashStr2, sizeStr2, i);
            if (index >= 0) {
                break;
            }
        }

        if (index >= 0) {
            std::cout << "Подстрока " << str2 << " найдена по индексу " << index << std::endl;
        }
        else std::cout << "Подстрока " << str2 << " не найдена" << std::endl;


    } while (str2 != "exit");
}

//int hash_(std::string str, int size) {
//    int hash = 0;
//
//    for (int i = 0; i < size; i++) {
//        hash += static_cast<int>(str[i]) * power(29, i) % 1000;
//    }
//    return hash;
//}
//
//int find_substring_light_rabin_karp_(std::string str, int &hashStr1, int hashStr2, int sizeStr2, int startPoint) {
//    int x = startPoint;
//    int prevSymbol = startPoint - 1;
//    int nextSymbol = startPoint + sizeStr2 - 1;
//
//    hashStr1 -= static_cast<int>(str[prevSymbol]) * power(29, 0) % 1000;
//    hashStr1 -= static_cast<int>(str[nextSymbol]) * power(29, sizeStr2) % 1000;
//
//    if (hashStr1 == hashStr2) {
//        return startPoint;
//    }
//    else return -1;
//}
//
//void test_() {
//    std::string str1, str2;
//    int sym = 0;
//
//    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
//    std::cin >> str1;
//    int sizeStr1 = str1.size();
//
//    do
//    {
//        std::cout << "Введите подстроку, которую нужно найти: ";
//        std::cin >> str2;
//        int sizeStr2 = str2.size();
//        int hashStr2 = hash_(str2, sizeStr2);
//
//        int index = 0;
//        int hashStr1 = 0;
//        for (int i = 0; i < str1.size() - sizeStr2; i++) {
//            if (i == 0) {
//                hashStr1 = hash_(str1, sizeStr2);
//            }
//            index = find_substring_light_rabin_karp_(str1, hashStr1, hashStr2, sizeStr2, i);
//            if (index >= 0) {
//                break;
//            }
//        }
//
//        if (index >= 0) {
//            std::cout << "Подстрока " << str2 << " найдена по индексу " << index << std::endl;
//        }
//        else std::cout << "Подстрока " << str2 << " не найдена" << std::endl;
//
//
//    } while (str2 != "exit");
//
//
//}

int main()
{
    setlocale(LC_ALL, "rus");
    //counting_hash();
    //counting_real_hash();

    test();

}