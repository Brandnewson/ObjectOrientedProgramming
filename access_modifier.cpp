#include <iostream>
using std::string;

// Every variable in a class is private by default,so you have to explicitly state for it to be public
class Employee {
public:
    string Name;
    string Company;
    int Age;

    void IntroduceYourself() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
};

int main() {
    Employee employee1;
    employee1.Name = "bob";
    employee1.Company = "Youtube";
    employee1.Age = 25;
}
