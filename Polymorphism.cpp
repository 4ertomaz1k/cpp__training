#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class Shape
{
private:
    std::string color_;

public:
    Shape(const std::string& color): color_(color) {};
    //virtual need for redefinitions
    virtual ~Shape() {};// destructor need to be virtual, because it based rool for any parent class, which will be used by polymorphism

    void setColor(std::string color)
    {
        color_ = color;
    }

    std::string getColor() const// const for security guarantee
    {
        return color_;
    }

    virtual void displayDimension() const
    {
        cout << "this is global figure" << endl;
    }

    virtual void displayShapeInfo() const
    {
        cout << "its a " << color_ << " shape" << endl;
    }

};


class Rectangle: public Shape 
{private:                     
    double width_;            
    double height_;                             
                            
public:
    Rectangle(double width, double height, const std::string& color) :Shape(color), width_(width), height_(height) {};

    double calculateArea() const
    {
        return width_ * height_;
    }

    void displayDimension() const override//redefinitions
        {
            cout << "this is " << getColor() << " rectangle with W:" << width_ << " H:" << height_ << endl;
        }

    void displayShapeInfo() const override//redefinitions but not used in main
    {
        cout << "its " << getColor() << " rectangle which square is " << calculateArea() << endl;
    }

};


class Circle: public Shape
{

private:
    int radius_;

public:
    Circle(int radius, const std::string& color): Shape(color), radius_(radius) {};

    void displayDimension() const override//redefinitions
    {
        cout << "this is " << getColor() << " circle, which radius is " << radius_<< endl;
    }

};


int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(10,5,"blue"));
    shapes.push_back(std::make_unique<Circle>(7, "yellow"));

    for (int i = 0; i < shapes.size(); i++ )
    {
        shapes[i]->displayDimension();
    }


    return 0;
}