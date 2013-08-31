#include <iostream>
using namespace std;
class Base
{
public:
    virtual void fun1(){}
    virtual void fun2()
    {
        cout << "Base:func2"<< endl;
    }
};
class A:public Base
{
public:
    void fun1()
    {
        cout << "A:func1" << endl;
        fun2();
    }
    /*void fun2()
    {
        cout << "a func2" << endl;
    }*/

};
class B:public Base
{
public:
    void fun1()
    {
        cout << "B:cun1" << endl;
        Base::fun2();
    }
};

int main(int argc, char* argv[])
//int main()
{
    A a; B b;
    a.fun1();
    b.fun1();
    int t = 0;
    cin >> t;
    return 0;
}
