#include <iostream>

#include "task 5-1.h"
#include "task 5-2.h"
#include "task 5-3.h"

//template <class T>
class func {
public:
	func() {
		sum = 0;
		count = 0;
	}
	void operator()(int num) {
		if (num % 3 == 0 && num != 0) {
			count++;
			sum += num;
		}
	}

	int getSum() {
		return sum;
	}
	int getCount() {
		return count;
	}

private:
	int sum, count;
};

int main()
{
    //task_5_1();
	//task_5_2();
	task_5_3();

	
}