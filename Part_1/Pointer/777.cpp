#include <iostream>

void swap(int*& p1, int*& p2) // (int **p1, int **p2)
{
    int* tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
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

    int* p1 = &a;
    int* p2 = &b;
    swap(p1, p2);

    std::cout << "a = " << *p1 << "\n";
    std::cout << "b = " << *p2 << "\n";

    return 0;
}