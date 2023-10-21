#include <iostream>
using std::string;

class Employee {

// We want to reduce complexity and increase reusability
// so we implement Encapsulation
// note that we don't actually have to put "private" but it's good coding habit

// wow look at these private member variables
private:
    string Name;
    string Company;
    int Age;

public:
    // Setters are for you to modify private member variables
    // Getters are for you to retrieve values of the private member variables

    // Setter for Name
    void setName(string name){
        Name = name;
    }
    // Getter for Name
    string getName(){
        return Name;
    }

    // Setter for Company
    void setCompany(string company){
        Company = company;
    }
    // Getter for Company
    string getCompany(){
        return Company;
    }

    // Setter for Age with validation
    void setAge(int age){
        // Validation rule: age must be 18 or higher
        if(age >= 18)
            Age = age;
    }
    // Getter for Age
    int getAge(){
        return Age;
    }

    // Constructor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main() {

    // Create two instances of Employee using constructor
    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
    Employee employee2 = Employee("John", "Amazon", 35);

    // Set the age of employee1 using the setAge method
    employee1.setAge(39);

    // Print out the name and age of employee 1 & 2
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl;
    std::cout << employee2.getName() << " is " << employee2.getAge() << " years old" << std::endl;

}
