#include <iostream>
#include <string>
#include <memory>

void pointer(std::string* Cats_)
{
    std::cout << "Link:" << std::endl;
    *Cats_ += '?';
}


void link(std::string& Cats_)
{
    std::cout << "Pointer:" << std::endl;
    Cats_ += '!';
}


void copy(std::string Cats_)
{   
    std::cout << "This is copy of Cats:" << std::endl;
    std::cout << Cats_ << std::endl;
    Cats_ += ')';
    std::cout << Cats_ << std::endl << std::endl;
}

int main()
{
    std::string Cats = "Cats";
    
    pointer(&Cats);
    std::cout << Cats << std::endl << std::endl;

    link(Cats);
    std::cout << Cats << std::endl << std::endl;

    copy(Cats);
    std::cout << "Thats result of original Cats:" << std::endl;
    std::cout << Cats << std::endl; 

    return 0;
}