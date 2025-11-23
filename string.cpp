#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string str;//  do a string type
    str = "Yo ";
    std::string str_2 = "kjfds&^%&$@%76!";

    str += str_2; // concatenate 
    cout << str<< endl;
    cout << str.length() << endl; //len
    cout << str.size() << endl; // also len

    return 0;
}