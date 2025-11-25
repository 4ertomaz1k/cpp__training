#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Shape
{
private:
    std::string color_;

public:
    Shape(const std::string& color): color_(color) {};

    void setColor(std::string color)
    {
        color_ = color;
    }

    std::string getColor() const// const for security guarantee
    {
        return color_;
    }

    void displayShapeInfo() const
    {
        cout << "its a " << color_ << " shape" << endl;
    }

};

class Rectangle: public Shape // public - inheritor's methods avaliable for all(parent class, descendant classes, any external code (main))
{private:                     // protected - inheritor's methods avaliable for parent class and descendant classes
    double width_;            // private - inheritor's methods avaliable only for parent class
    double height_;                             
                            
public:
    Rectangle(double width, double height, const std::string& color) :Shape(color), width_(width), height_(height) {};

    double calculateArea() const
    {
        return width_ * height_;
    }

    void displayShapeInfo() const
    {
        cout << "its " << getColor() << " rectangle which square is " << calculateArea() << endl;
    }
};



int main()
{
    std::unique_ptr<Rectangle> created_rectangle = std::make_unique<Rectangle>(10.0, 5.0, "red"); // reactangle, rectangle -> ptr references on rectangle and create rectangle object -> inhertitance shape -> and knew shape methods
    created_rectangle->getColor();// parent's method                                              if shape, rectangle ->  ptr references on shape and create rectangle object -> you known only shape methods, btw you rectangle
    created_rectangle->displayShapeInfo();// overrided method
    return 0;
}