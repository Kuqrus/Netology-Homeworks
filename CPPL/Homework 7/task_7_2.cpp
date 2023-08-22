#include "task_7_2.h"

void task_7_2() {
    int size = 0;
    int inputNum;
    std::cout << "Enter size: ";
    std::cin >> size;
    std::vector<int> nums;

    while (size-- != 0) {
        std::cin >> inputNum;
        nums.push_back(inputNum);
    }

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
        });
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (const auto& el : nums) {
        std::cout << el << " ";
    }
}