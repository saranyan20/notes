#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    public:
        int id;
        string name;
        string dept;
        friend ofstream& operator<<(ofstream &ofs, Student &s);
        friend ifstream& operator>>(ifstream &ifs, Student &s);
        friend ostream& operator<<(ostream &os, Student &s);
};
ofstream& operator<<(ofstream &ofs, Student &s)
{
    ofs << s.id << endl;
    ofs << s.name << endl;
    ofs << s.dept << endl;
    return ofs;
}
ifstream& operator>>(ifstream &ifs, Student &s)
{
    ifs >> s.id;
    ifs >> s.name;
    ifs >> s.dept;
    return ifs;
}
ostream& operator<<(ostream &os, Student &s)
{
    os << s.id << endl;
    os << s.name << endl;
    os << s.dept << endl;
}

int main()
{
    Student s1;
//    s1.id = 02;
//    s1.name = "Saran";
//    s1.dept = "CSE";
//    ofstream ofs("student.txt",ios::app);
//    ofs << s1;

    ifstream ifs;
    ifs.open("student.txt");
    ifs >> s1;
    cout << s1 << s1;
    return 0;
}
