#include <iostream>
using namespace std;
class Shape
{
    public:
        //virtual void draw(const string color="red") = 0;
        virtual void draw(const string color="red")
        {
            cout << "shape draw :" << color << endl;
        }
};

class Rectangle : public Shape
{
    public:
        virtual void draw(const string color="green")
        {
            cout << "rectangle draw : " << color << endl;
        }
};

class Circle : public Shape
{
    public:
    virtual void draw(const string color)
    {
        cout << "circle draw " << color << endl;
    }
};

int main()
{
    Shape * ps;
    Shape *pc = new Circle;
    Shape *pr = new Rectangle;
    pc->draw();
    pc->draw("black");
    pr->draw();

    return 0;
}
