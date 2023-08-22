#include "task_7_1.h"

void task_7_1() {
    std::map<char, int> symbols;
    std::string str = "HelloO world!!";
    for (const auto& el : str) {
        int count = 0;
        for (const auto& check : str) {
            if (el == check) {
                count++;
            }
        }
        symbols.insert(std::make_pair(el, count));
    }

    std::multimap<int, char> sorted;
    for (const auto& el : symbols) {
        sorted.insert({ el.second, el.first });
    }
    std::cout << "IN: " << str << "\nOUT:" << std::endl;
    for (auto i = sorted.crbegin(); i != sorted.crend(); i++) {
        std::cout << (*i).second << ": " << (*i).first << std::endl;
    }

}