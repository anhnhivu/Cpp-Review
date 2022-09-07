#include <iostream>

bool allEvenDigits(int n) 
{
    if (n == 0)
        return true;
    if (n % 2 == 1)
        return false;
    return allEvenDigits(n / 10);
}

int main() 
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (allEvenDigits(n)) 
       std:: cout << n << " contains only even digits.\n";
    else 
        std::cout << n << " does not contain only even digits.\n";
    
    return 0;
}