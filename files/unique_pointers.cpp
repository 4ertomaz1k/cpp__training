#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Animals
{
private:
  std::string name_;

//name - temporary, for constructor, and died after end of function;  constructor copy name to name_ and name_ is constant and gives to destructor after deat of object
public:
 /*constructor*/ Animals(const std::string& name): /*data transmission from name to name_*/ name_(name)  { cout << "Your animal -" << name << " is created" << endl; }
 /*destructor*/  ~Animals() { cout << "Your animal -" << name_ << " is died"<<endl; }
};

void create_animals()
{
  std::unique_ptr<Animals> hodgehog = std::make_unique<Animals>(" hodgehog");// create ptr for Animals type and named his - hodgehod.  malloc for Animals type and give "hodgehog" for constuctor
  std::unique_ptr<Animals> dog = std::make_unique<Animals>(" dog"); //the same as in the 21 line.
}



int main()
{
  setlocale(LC_CTYPE, "Russian");

  create_animals();

  return 0;
}