#include <iostream>
using std::string;

// Abstract base class AbstractEmployee
class AbstractEmployee {
    virtual void AskForPromotion()=0;
};

// Derived class Employee, inherits from AbstractEmployee
class Employee:AbstractEmployee {
private:
    string Company;
    int Age;

protected:
    string Name;

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

    // Constructor to initialize Employee object with provided values
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    // AskForPromotion Method, any class derived from AbstractEmployee MUST use this function
    void AskForPromotion(){
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << " sorry NO promotion for you!" << std::endl;
    }
};

// Subclass inherits from Superclass Employee
// to get access to other properties from a superclass, make the class of Developer public.
class Developer: public Employee {
public:
    // initialise an additional property, specifically for Developer
    string FavProgrammingLanguage;
    // Constructor for Developer class
    // Specific properties to developer has to be created
    // constructors that have been declared in Employee class don't have to declared again
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name,company,age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        // note you cannot access "Name", still need to use a getter
        // especially because you're accessing it from another class.
        // BUT this is a protected property, so subclasses can access it.
        std::cout<< Name <<" fixed bug using " << FavProgrammingLanguage << std::endl;
    }
};

// Subclass Teacher, inheritance from Superclass Employee
class Teacher: public Employee {
public:
    string Subject;
    // a functionality that is strictly for the Teacher class to use
    void PrepareLesson() {
        std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
    }

    // Constructor for Teacher class
    // stating that you are inheriting the Employee class extracting properties name, company & age

    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }

};

int main() {
    // Create an instance of Developer using the Developer Constructor
    // if you just do Developer d;, you will require a constructor for the developer class.
    Developer d = Developer("Saldina", "YT-CodeBeauty", 25, "C++");

    // Create an instance of Teacher using the Teacher Constructor
    Teacher t = Teacher("Jack", "Cool School", 35, " History");

    // Call Fixbug Method for Developer
    d.FixBug();
    d.FixBug();
    d.FixBug();
    d.FixBug();

    // Call PrepareLesson Method for Teacher
    t.PrepareLesson();

}
