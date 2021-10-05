#include <iostream>
#include "triangle.h"
using namespace std;

void test(Triangle t, const char * prefix="Test Triangle"){
    double peri, x;
    show(t,prefix);
    peri = perimeter(t);
    if(!peri) {
        cout << "Bad parameters\n";
        return;
    }
    x = area(t);
    cout<<"area ="<<x<<endl<<"perimeter="<<peri<<endl<<endl;
}

int main(int argc, char const *argv[])
{
    cout<<"sizeof(Triangle)="<<sizeof(Triangle)<<endl;

    Triangle t1={3,4,5};
    test(t1,"t1");

    Triangle t2={1,1,1};
    test(t2,"t2");

    Triangle t3={3,4,12};
    test(t3, "t3");

    return 0;
}