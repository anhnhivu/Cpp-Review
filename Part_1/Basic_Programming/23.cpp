#include <iostream>

int numberOfDivisors(int n) 
{
    if (n == 1)
        return 1;
    int totalNumberOfDivisors = 2; // n always has two divisors: 1 and itself
    for (int i = 2; i <= n/2; i++) // change from `< n` to `<= n/2` to reduce the numbers of iteration
    {
        if (n % i == 0) 
            totalNumberOfDivisors++;
    }
    return totalNumberOfDivisors;
}

int main() 
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    
    if (n < 1)
        std::cout << "Not a valid positive integer.\n";
    else
        std::cout << "Total number of divisors for " << n << " is: " << numberOfDivisors(n) << "\n";

    return 0;
}