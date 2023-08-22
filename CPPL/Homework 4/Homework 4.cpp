#include <iostream>
#include "List.h"


int main()
{

    List testList;

    for (int i = 0; i < 10; i++) {
        testList.PushBack(std::rand() % 100);
    }

    std::cout << "List size: " << testList.Size() << ::std::endl;
    std::cout << "List is empty: " << testList.Empty() << ::std::endl;

    testList.Clear();

    std::cout << "List size: " << testList.Size() << ::std::endl;
    std::cout << "List is empty: " << testList.Empty() << ::std::endl;

	return 0;
}
