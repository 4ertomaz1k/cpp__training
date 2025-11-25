#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Book
{
private: // private variables, cant be caused out of class
std::string title_;
std::string author_;

public:
    Book(const std::string& title, const std::string& author): title_(title), author_(author) // constructor with 2 arguments; private variables get data by public variables
    {cout << "Object type Book is succesffully created" << endl;};
    
    ~Book() {cout << "Book: "<< title_ <<" - "<< author_ << " is succesffully destroyed "<< endl;}; //destructor

    void displayInfo()
    {
        cout << "Book name: " << title_ <<  endl;
        cout << "Author: " << author_ << endl;
    }
    
};


int main()
{
    std::unique_ptr<Book> Book_1 = std::make_unique<Book> ("Harry Potter", "Joahn Roawling"); //create object and give 2 arguments to constuctor
    Book_1->displayInfo(); // calling the method

    std::unique_ptr<Book> Book_2 = std::make_unique<Book> ("Fighter club", "Chack Palanik");
    Book_2->displayInfo();

    return 0;
}