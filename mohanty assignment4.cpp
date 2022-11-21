#include <iostream>
#include <fstream>
using namespace std;
class Bank
{
protected:
    string name;
    int accno;
    float balance;

public:
    Bank(string a, int b, float c)
    {
        name = a;
        accno = b;
        balance = c;
    }
    virtual void withdraw() = 0; // virtual function
};
class current : public Bank // inheritence
{
    float overdue;

public:
    current(string a, int b, float c, float d) : Bank(a, b, c) // constructor in inheritence
    {
        overdue = d;
    }
    void withdraw()
    {
        if (overdue > 0)
        {
            balance = balance - overdue;
        }
        int a;
        cout << "Enter the amount to withdraw : ";
        cin >> a;
        if (a > balance)
        {
            cout << "money cant be withdrawn ";
            exit(1);
        }
        else
        {
            balance = balance - a;
        }
        cout << "Money left = " << balance << endl;
    }
};
class Savings : public Bank
{
public:
    Savings(string a, int b, float c) : Bank(a, b, c)
    {
    }
    void withdraw()
    {
        int a;
        cout << "Enter the amount to withdraw : ";
        cin >> a;
        if (a > balance)
        {
            cout << "money cant be withdrawn ";
            exit(1);
        }
        else
        {
            balance = balance - a;
        }
        cout << "Money left = " << balance << endl;
    }
};
class dist1
{
    int km, m;

public:
    // dist1();
    dist1(int a = 0, int b = 0) // default and parameterised constructor
    {
        km = a;
        m = b;
    }
    dist1 operator+(dist1 d1) // operator overloading
    {
        dist1 temp;
        temp.km = km + d1.km;
        temp.m = m + d1.m;
        return temp;
    }
    void display()
    {
        cout << km << " km " << m << " m " << endl;
    }
};
inline int sum(int a, int b) // inline function
{
    return a + b;
}
inline float sum(float a, float b) // function overloading
{
    return a + b;
}
int main()
{
    int choice;
    cout << "1.function overloading and inline function \n2. class and object,constructor and operator overloading";
    cout << "\n3.virtual function and inheritence with constructors\n 4.file handling";
start:
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        int a, b;
        float c, d;
        cout << "Enter two integers: ";
        cin >> a >> b;
        cout << "Enter two floating point numbers : ";
        cin >> c >> d;
        cout << "Sum of both integers is : " << sum(a, b) << endl;
        cout << "Sum of both floating numbers is : " << sum(c, d) << endl;
        goto start;
    case 2:
    {
        dist1 d1(5, 200), d2(3, 42);
        dist1 d3;
        d3 = d1 + d2;
        d1.display();
        d2.display();
        d3.display();
       goto start;
    }
    case 3:
    {
        current c1("Ayush", 21999, 600000, 30000);
        c1.withdraw();
        Savings s1("Amit", 32465, 900000);
        s1.withdraw();
        goto start;
    }
    case 4:
        ifstream file1("text");                    //file and file handling
        ofstream file2("reverse copy");
        file1.seekg(0, ios::end);
        int len = file1.tellg();
        char ch;
        for (int i = 1; i <= len; i++)
        {
            file1.seekg(-i, ios::end);
            file1.get(ch);
            file2.put(ch);
        }
        file1.close();
        file2.close();
        goto start;
    }
    return 0;
}
