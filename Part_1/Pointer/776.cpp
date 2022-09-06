#include <iostream>

int main() 
{
    int *p = new int[100];
    delete[] p;
    return 0;
}