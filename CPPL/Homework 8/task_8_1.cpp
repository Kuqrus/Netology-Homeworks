#include "task_8_1.h"

void DeleteDuplicates(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
}
void task_8_1() {
    std::vector<int> nums{ 5,2,1,1,2,3,2,4,5,3,4,4 };

    std::cout << "With duplicates:\n";
    for (auto& el : nums) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    DeleteDuplicates(nums);

    std::cout << "Without duplicates:\n";
    for (auto& el : nums) {
        std::cout << el << " ";
    }
    std::cout << std::endl << std::endl;
}
