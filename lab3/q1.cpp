#include <iostream>

using namespace std;

template <typename T>
void swap_values(T &a, T &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

template <typename R>
void swap_string(R &a, R &b)
{
    string temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 5;

    double val1 = 19.4;
    double val2 = 78.45;

    string str1 = "hello";
    string str2 = "world";

    cout << "Integer 1 before swap: " << a << endl;
    cout << "Integer 2 before swap: " << b << endl;
    swap_values(a, b);
    cout << "Integer 1 after swap: " << a << endl;
    cout << "Integer 2 after swap: " << b << endl;
    cout << endl;

    cout << "Double 1 before swap: " << val1 << endl;
    cout << "Double 2 before swap: " << val2 << endl;
    swap_values(val1, val2);
    cout << "Double 1 after swap: " << val1 << endl;
    cout << "Double 2 after swap: " << val2 << endl;
    cout << endl;

    cout << "String 1 before swap: " << str1 << endl;
    cout << "String 2 before swap: " << str2 << endl;
    swap_string(str1, str2);
    cout << "String 1 after swap: " << str1 << endl;
    cout << "String 2 after swap: " << str2 << endl;
    cout << endl;

    return 0;
}