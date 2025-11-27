#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::cin;
using std::endl;


class Worker
{

public:
    virtual ~Worker() {};//of course neeed to virtual distructor

    virtual void calculateSalary() const = 0;//pure virtual function
    virtual void performWork() const = 0;//pure virtual function
    //this parent class is pattern for children, in which you necessarily need to redefine all of this functions

    int id;
    void printID() const {cout << "Worker ID: " << id << endl;}// not virtual method!

};



class HourlyWorker: public Worker
{

    private:
        int hours_;
        double rate_;

    public:
        HourlyWorker(int hours, double rate): hours_(hours), rate_(rate) {};

        void performWork() const override// 1/2 necessarily redefinition
        {
            cout << "Executing assigned tasks and logging 8 hours of work time." << endl;
        }

        void calculateSalary() const override// 2/2 necessarily redefinition
        {
            cout << "Current salary is " << hours_ * rate_ <<"$"<< endl << endl; 
        }

};



class Manager: public Worker
{

    private:
        double baseSalary_, bonus_;

    public:
        Manager(double baseSalary, double bonus): baseSalary_(baseSalary), bonus_(bonus) {};

        void performWork() const override// 1/2 necessarily redefinition
        {
            cout << "Reviewing team performance, budgets, and setting strategic goals." << endl;
        }

        void calculateSalary() const override// 2/2 necessarily redefinition
        {
            cout << "Current salary is " << baseSalary_ + bonus_ <<"$"<< endl << endl; 
        }

};



int main()
{

    std::unique_ptr<HourlyWorker> hourlyworker = std::make_unique<HourlyWorker>(120, 3.8);
    hourlyworker->id=4432; hourlyworker->printID();//call of not virtual method
    hourlyworker->performWork();//polymorphic call
    hourlyworker->calculateSalary();//polymorphic call

    
    std::unique_ptr<Manager> manager = std::make_unique<Manager>(900, 150);
    manager->id=128; manager->printID();//call of not virtual method
    manager->performWork();//polymorphic call
    manager->calculateSalary();//polymorphic call
    
    return 0;
}