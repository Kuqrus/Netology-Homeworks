#include <iostream>

struct bankAcc
{
    int number;
    std::string name;
    double balance;
};

void newBankAcc(struct bankAcc& user) {
    std::cout << "������� ����� ����: ";
    std::cin >> user.number;

    std::cout << "������� ��� ���������: ";
    std::cin >> user.name;

    std::cout << "������� ������: ";
    std::cin >> user.balance;
}

void newBalance(double& currentBalance)
{
    std::cout << "������� ����� ������: ";
    std::cin >> currentBalance;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    bankAcc andrey;
    newBankAcc(andrey);

    std::cout << "������� ���������� �� �����:\n����� �����: " << andrey.number << ". ��� ���������: " << andrey.name << ". ������: " << andrey.balance << std::endl;

    newBalance(andrey.balance);

    std::cout << "������� ���������� �� �����:\n����� �����: " << andrey.number << ". ��� ���������: " << andrey.name << ". ������: " << andrey.balance << std::endl;

}

