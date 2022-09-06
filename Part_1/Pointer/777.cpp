#include <iostream>

void swap(int *p1, int *p2) 
{
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    return;
}

int main() 
{
    int a;
    int b;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;

    swap(&a, &b);
    
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    return 0;
}