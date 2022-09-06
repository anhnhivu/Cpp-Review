#include <iostream>

int isPowerOf2(int n) 
{
    if (n <= 0) // if n is negative, it is not a power of 2. 
        return false; 
    while (n > 1) 
    {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }
    return true;
}

int main() 
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (isPowerOf2(n))
        std::cout << n << " is a power of 2.\n";
    else
        std::cout << n << " is not a power of 2.\n";

    return 0;
}