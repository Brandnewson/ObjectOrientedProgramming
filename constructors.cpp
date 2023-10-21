#include <iostream>
using std::string;

class Employee {
public:
    string Name;
    string Company;
    int Age;

    // Method
    void IntroduceYourself() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    // Constructors have to be defined here,
    // Constructors MUST take the same name as the class.
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main() {

    // construct the object
    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
    // calls the employee constructor, passes values there, and constructs what's given.
    employee1.IntroduceYourself();
    Employee employee2 = Employee ("John", "Amazon", 35);
    employee2.IntroduceYourself();
}
