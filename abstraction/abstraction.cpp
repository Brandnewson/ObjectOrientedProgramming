#include <iostream>
using std::string;

// Reduce complexity and isolate impact of change with ABSTRACTION

class AbstractEmployee {
    // to make this obligatory, make it a virtual function
    // i.e. you must use this virtual method
    // marked as pure virtual with "=0"
    virtual void AskForPromotion()=0;
};

// Derived class employee, inherits from AbstractEmployee
class Employee:AbstractEmployee {
private:
    string Name;
    string Company;
    int Age;

public:
    // Setters and Getters for Name, Company, and Age
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }

    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }

    void setAge(int age){
        if(age>=18)
            Age = age;
    }
    int getAge(){
        return Age;
    }

    // Constructor to initialise Employee Object with provided values
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    // AskForPromotion() method from the base class
    void AskForPromotion(){
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << " sorry NO promotion for you!" << std::endl;
    }
};

int main() {
    // Create 2 instances
    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
    Employee employee2 = Employee ("John", "Amazon", 35);

    // Call for AskForPromotion method for both employees
    employee1.AskForPromotion();
    employee2.AskForPromotion();
}
