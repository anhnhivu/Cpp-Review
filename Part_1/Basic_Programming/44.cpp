#include <iostream>

int sumOfDigits(int n) 
{
    int sumOfDigits = 0;
    while (n > 0) 
    {
        sumOfDigits += (n % 10);
        n /= 10;
    }
    return sumOfDigits;
}

int main() 
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n < 1)
        std::cout << "Not a valid positive integer.\n";
    else
        std::cout << "Sum of digits of " << n << " is: " << sumOfDigits(n) << "\n";

    return 0;
}