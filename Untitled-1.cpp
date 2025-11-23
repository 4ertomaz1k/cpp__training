#include <iostream>
#include <locale.h>
#include <vector>
#include <string>


using std::cin;
using std::cout;
using std::endl;


int main()
{
	setlocale(LC_CTYPE, "Russian");

	std::vector<int> numbers;//create array for integers and named his - numbers

	for (int i = 1; i <= 10; i++)
	{
		numbers.push_back(i * 10);//add element in array
		cout << i << "й элемент массива = " << i * 10 << endl;
	}
	cout << numbers.size();//len

	return 0;
}






