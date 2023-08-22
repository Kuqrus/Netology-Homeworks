////Введите точку отсчёта : 32
////Количество элементов в массиве больших, чем 32 : 3
////Введите точку отсчёта : 15
////Количество элементов в массиве больших, чем 15 : 8
//#include <iostream>
//
//int main()
//{
//	int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
//	//			  0	  1	  2	  3	  4	  5	  6	  7	  8		== 9
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	int left = 0;
//	int right = size - 1;
//	int middle = 0;
//
//	int num = 70;
//	int summ = 0;
//
//
//
//	while (left <= right) {
//		middle = (left + right) / 2;
//		if (arr[middle] <= num) {
//			left = middle + 1;
//		}
//		else {
//			right = middle - 1;
//		}
//	}
//
//	summ = size - left;
//
//	std::cout << "numbers larger than " << num << " in arr: " << summ << std::endl;
//
//	
//}