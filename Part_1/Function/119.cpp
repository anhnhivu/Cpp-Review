#include <iostream>
#include <math.h>

bool isPrime(int k)
{
    if (k <= 1)
        return false;
    for (int i = 2; i <= sqrt(k); i++)
        if (k % i == 0)
            return false;
    return true;
}

void printSmallerPrimeNumbers(int n)
{
    std::cout << "List of prime numbers smaller than " << n << ": ";
    if (n <= 2)
        std::cout << "None.";
    for (int i = 2; i < n; i++)
        if (isPrime(i))
            std::cout << i << " ";
    std::cout << "\n";
}

int main()
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n < 1)
        std::cout << "Not a valid integer";
    else
        printSmallerPrimeNumbers(n);

    return 0;
}