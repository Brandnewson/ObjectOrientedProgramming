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

    // Polymorphism! See how this general function is written in the Employee Class
    // Any Subclass that inherits from the Employee superclass, can use this function
    void Work(){
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
    // THEN, a functionality in a subclass can be modified, and be used differently.
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

    // modifying, i.e. overriding the Work() Method in a subclass
    void Work(){
        std::cout << Name << " is teaching " << Subject << " really well" << std::endl;
    }

};

int main() {
    Developer d = Developer("Saldina", "YT-CodeBeauty", 25, "C++");
    d.FixBug();

    Teacher t = Teacher("Jack", "Cool School", 35, " History");
    t.PrepareLesson();

    // though these two are the same functions, due to the fact it has its own functions
    // it will give it its own output
    d.Work();
    t.Work();
}
