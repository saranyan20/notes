#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int emp_id;
    string emp_name;
public:
    Employee(int emp_id, string emp_name);
    int getId();
    string getName();
};

class ParttimeEmployee:public Employee
{
private:
    int wages;
public:
    ParttimeEmployee(int emp_id, string emp_name, int wages);
    void Display();
};

class FulltimeEmployee:public Employee
{
private:
    int salary;
public:
    FulltimeEmployee(int emp_id, string emp_name, int salary);
    void Display();
};

int main()
{
    ParttimeEmployee pe(01,"Saran",100000);
    FulltimeEmployee fe(02,"Siva",90000);
    pe.Display();
    cout << endl;
    fe.Display();
    return 0;
}

// Employee Class
Employee::Employee(int emp_id, string emp_name)
{
    this->emp_id = emp_id;
    this->emp_name = emp_name;
}
int Employee::getId() { return emp_id; }
string Employee::getName() { return emp_name; }

// Parttime Employee Class
ParttimeEmployee::ParttimeEmployee(int emp_id, string emp_name, int wages):Employee(emp_id,emp_name)
{
    this->wages = wages;
}
void ParttimeEmployee::Display()
{
    cout << "Part time wage of " << getName() << " of id " << getId() << " is " << wages;
}

// Fulltime Employee Class
FulltimeEmployee::FulltimeEmployee(int emp_id, string emp_name, int salary):Employee(emp_id,emp_name)
{
    this->salary = salary;
}
void FulltimeEmployee::Display()
{
    cout << "Full time salary of " << getName() << " of id " << getId() << " is " << salary;
}
