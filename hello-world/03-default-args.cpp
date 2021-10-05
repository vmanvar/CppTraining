#include <iostream>
#include <math.h>

double power(double num, double exp = 2) {
    return pow(num,exp);
}

int main() {
    int a = 20;
    int *p;
    std::cout << "power(2,3) = " << power(2,3) << "\n";
    std::cout << "power(2) = " << power(2) << "\n";

    p = &a;
    std::cout << "p = " << p << ", *p = " << *p << "\n";
    std::cout << "p = " << p << ", *++p = " << *++p << "\n";
    std::cout << "p = " << p << ", *p = " << *p << "\n";
    return 0;
}