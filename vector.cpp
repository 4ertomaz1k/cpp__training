#include <iostream>
#include <vector> // for array - vector

using std::cin;
using std::cout;
using std::endl;


int main()
{
	std::vector<int> numbers;//create array for integers and named his - numbers

	for (int i = 1; i <= 10; i++)
	{
		numbers.push_back(i * 10);//add element in array
		cout << i << "th element of array = " << i * 10 << endl;
	}
	cout << numbers.size();//len

	return 0;
}






