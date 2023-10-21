#include <iostream>
using std::string;

class AbstractEmployee {
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee {
private:
    string Company;
    int Age;

protected:
    string Name;

public:
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

    void IntroduceYourself(){
    }
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion(){
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << " sorry NO promotion for you!" << std::endl;
    }

    // a virtual function
    // the most derived function (the subclass functions) will be executed when available
    virtual void Work(){
        std::cout << Name << " is checking email, task backlog, performing tasks...";
    }
};

class Developer: public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage):Employee(name,company,age){
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        std::cout<< Name <<" fixed bug using " << FavProgrammingLanguage << std::endl;
    }
    void Work(){
        std::cout << Name << " is writing " << FavProgrammingLanguage << " code" << std::endl;
    }
};

class Teacher: public Employee {
public:
    string Subject;
    void PrepareLesson() {
        std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
    }

    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }

    // Commented out to show that it will take the most derived function available.
//    void Work(){
//        std::cout << Name << " is teaching " << Subject << " really well" << std::endl;
//    }

};

int main() {
    Developer d = Developer("Saldina", "YT-CodeBeauty", 25, "C++");

    Teacher t = Teacher("Jack", "Cool School", 35, " History");

    // because ultimately our developer subclass is an employee superclass, you need to do this when pointing
    Employee* e1 = &d;
    Employee* e2 = &t;

    // simply submitting this code will not work, because work functionality that corresponds to d and t are not accessible
    e1->Work();
    e2->Work();
}
