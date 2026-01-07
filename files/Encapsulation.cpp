#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::endl;

class TemperatureSensor
{
private:
    double temperature_; //private because it need only for this class fot return
    const double ABSOLUTE_ZERO = -273.15; //private beacause if not it stupid and cant be override

public:

    
    void setTemperature(double new_Temp)
    {
        if (new_Temp < ABSOLUTE_ZERO)
        {
           cout << "error: temperature" << endl;
            cout << "this temperature cant be real, because the lowest temperature equals -273.15 " << endl;
        }
        else
        {
            temperature_ = new_Temp;
            cout << "temperature successfully installed in " << temperature_ << endl;
        }
    }

    double getTemperature() const
    {
        return temperature_;
    }

};

int main()
{
    std::unique_ptr<TemperatureSensor> sensor_1 = std::make_unique<TemperatureSensor> ();
    sensor_1->setTemperature(25.0);//successfully installed
    
    sensor_1->setTemperature(-300.0);// not installed due error and current temperature - 25
    cout << "current temperature: " << sensor_1->getTemperature() << endl;

    return 0;
}