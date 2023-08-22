#include <iostream>

class calculator {
public:
    double num1;
    double num2;

    bool set_num1(double num1_) {
        if (num1_ != 0) {
            num1 = num1_;
            return true;
        }
        else return false;
    };

    bool set_num2(double num2_) {
        if (num2_ != 0) {
            num2 = num2_;
            return true;
        }
        else return false;
    };

    double add() { return num1 + num2; }
    double subtract_1_2() { return num1 - num2; }
    double subtract_2_1() { return num2 - num1; }
    double multiply() { return num1 * num2; }
    double divide_1_2() { return num1 / num2; }
    double divide_2_1() { return num2 / num1; }

    void print();

};

void calculator::print() {
    std::cout << "num1 + num2 = " << add() << std::endl;
    std::cout << "num1 - num2 = " << subtract_1_2() << std::endl;
    std::cout << "num2 - num1 = " << subtract_2_1() << std::endl;
    std::cout << "num1 * num2 = " << multiply() << std::endl;
    std::cout << "num1 / num2 = " << divide_1_2() << std::endl;
    std::cout << "num2 / num1 = " << divide_2_1() << std::endl;
}

int main()
{
    calculator number;

    while (true) {        

        double x = 0, y = 0;

        std::cout << "Enter num1: ";
        std::cin >> x;
        if (!number.set_num1(x)) {
            do
            {
                std::cout << "Incorrect input! Try again: ";
                std::cin >> x;

            } while (!number.set_num1(x));            
        }

        std::cout << "Enter num2: ";
        std::cin >> y;
        if (!number.set_num2(y)) {
            do
            {
                std::cout << "Incorrect input! Try again: ";
                std::cin >> y;

            } while (!number.set_num2(y));
        }

        number.print();

        std::cout << std::endl;
        system("pause");
        system("cls");
    }
    

}


