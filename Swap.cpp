#include <iostream>

void swap(int * x, int * y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    int a = 84;
    int b = -72;
    int * pa = &a;
    int * pb = &b;
    swap(pa,pb);
    std::cout << pa << " " << a << " " << b << std::endl;
    return 0;
}