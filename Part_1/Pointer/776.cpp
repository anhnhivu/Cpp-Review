#include <iostream>

int main() 
{
    int *p = new int[100];
    if (p != nullptr)
        delete[] p;
    p = nullptr;
    return 0;
}