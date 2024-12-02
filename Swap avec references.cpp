#include<iostream>

void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

int main() {
    int a = 84;
    int b = -72;
    int& ra = a;
    int& rb = b;
    swap(ra,rb);
    std::cout << a << " " << b << std::endl;
    return 0;
}