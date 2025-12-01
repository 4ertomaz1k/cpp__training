#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 1. ШАБЛОННАЯ ФУНКЦИЯ MAXIMUM
template <typename T>
T Maximum(T a, T b) {
    return (a > b) ? a : b;
}

// 2. ШАБЛОННЫЙ КЛАСС PAIR
template <typename T1, typename T2>
class Pair {
private:
    T1 first_;
    T2 second_;
public:
    // Конструктор
    Pair(T1 first, T2 second) : first_(first), second_(second) {}

    // Геттеры (должны быть константными, так как не меняют состояние)
    T1 get_first() const { return first_; }
    T2 get_second() const { return second_; }
};


int main() {
    cout << "--- Testing Maximum Function ---" << endl;
    
    // Тест 1: int
    cout << "Max (5, 10): " << Maximum(5, 10) << endl; 
    
    // Тест 2: double
    cout << "Max (3.14, 2.71): " << Maximum(3.14, 2.71) << endl;

    // Тест 3: string (сравнивается лексикографически)
    cout << "Max (Banana, Apple): " << Maximum(string("Banana"), string("Apple")) << endl; 
    
    cout << "\n--- Testing Pair Class ---" << endl;
    
    // Тест 4: Pair<int, string>
    Pair<int, string> employee_data(42, "Alice");
    cout << "Employee ID: " << employee_data.get_first() << ", Name: " << employee_data.get_second() << endl;

    // Тест 5: Pair<double, double>
    Pair<double, double> point(1.5, 9.9);
    cout << "Point coordinates: (" << point.get_first() << ", " << point.get_second() << ")" << endl;

    return 0;
}