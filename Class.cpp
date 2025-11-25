#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Book
{
private:
std::string title_;
std::string author_;

public:
    Book(const std::string& title, const std::string& author): title_(title), author_(author) 
    {cout << "Object type Book is succesffully created" << endl;};
    
    ~Book() {cout << "Book: "<< title_ <<" - "<< author_ << " is succesffully destroyed "<< endl;};

    void displayInfo()
    {
        cout << "Book name: " << title_ <<  endl;
        cout << "Author: " << author_ << endl;
    }
    
};


int main()
{
    std::unique_ptr<Book> Book_1 = std::make_unique<Book> ("Harry Potter", "Joahn Roawling");
    Book_1->displayInfo();

    std::unique_ptr<Book> Book_2 = std::make_unique<Book> ("Fighter club", "Chack Palanik");
    Book_2->displayInfo();

    return 0;
}