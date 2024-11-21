#include <iostream>
using namespace std;

class Person{
    private:
        string name;
        int age;

    public:
        void setName(string Name){
            name = Name;
        }
        void setAge(int Age){
            age = Age;
        }
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }

        virtual void displayInfo(){
            cout << "Person Details: " << endl;
            cout << "Name: " << name << endl;
            cout << "Age: "  << age << endl;
        }
};

class Employee: public Person{
    private:
    int employeeID;

    public:
        void setID(int ID){
            employeeID = ID;
        }
        int getID(){
            return employeeID;
        }

        void displayInfo() {
            cout << endl;
            cout << "Employee Details: " << endl;
            cout << "Name: " << getName() << endl;
            cout << "Age: "  << getAge() << endl;
            cout << "ID: " << getID() << endl;
            cout << endl;
    }
};

class Student: public Person{
    private:
        int studentID;

    public:
        void setID(int ID){
                studentID = ID;
        }
        int getID(){
            return studentID;
        }
        void displayInfo(){
            cout << endl;
            cout << "Student Details: " << endl;
            cout << "Name: " << getName() << endl;
            cout << "Age: "  << getAge() << endl;
            cout << "ID: " << getID() << endl;
        }
};

int main(){

    Person* Personptr;
    Employee EmployeeInfo; 
    Student studentInfo;

    EmployeeInfo.setName("Ali");
    EmployeeInfo.setAge(25);
    EmployeeInfo.setID(123);
    Personptr = &EmployeeInfo;
    Personptr -> displayInfo();
    cout << endl;

    studentInfo.setName("Eraj");
    studentInfo.setAge(19);
    studentInfo.setID(062);
    Personptr = &studentInfo;
    Personptr -> displayInfo();
    return 0;
}