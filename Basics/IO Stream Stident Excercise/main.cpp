#include <iostream>
#include <fstream>
using namespace std;

class Item
{
    public:
        string item;
        int qtn;
        int price;
        friend ofstream& operator<<(ofstream &ofs, Item &t);
        friend ifstream& operator>>(ifstream &ifs, Item &t2);
        friend ostream& operator<<(ostream &os, Item &t2);
};

ofstream& operator<<(ofstream &ofs, Item &t)
{
    ofs << t.item << " ";
    ofs << t.price << " ";
    ofs << t.qtn << " " << endl;
    return ofs;
}
istream& operator>>(istream &ifs, Item &t2)
{
    ifs >> t2.item;
    ifs >> t2.price;
    ifs >> t2.qtn;
    return ifs;
}
ostream& operator<<(ostream &os, Item &t2)
{
    os << t2.item << endl;
    os << t2.price << endl;
    os << t2.qtn << endl;
    return os;
}
int main()
{
    Item t;
    ifstream ifs;
    ofstream ofs;
    int n;
    cout << "Enter the no of items: ";
    cin >> n;

//    ofs.open("item.txt");
//    ofs << "Item    Qtn     Price" << endl;
//    cout << "Enter the values" << endl;
//    for(int i=0 ; i<n ; i++)
//    {
//        cout << "Item      Qtn     Price"<< endl;
//        cin >> t.item >> t.qtn >>t.price;
//        ofs << t;
//    }

    Item t2;
    ifs.open("item.txt");
    for(int i=0 ; i<n ; i++)
    {
        ifs >> t2;
        cout << t2;
    }



    return 0;
}
