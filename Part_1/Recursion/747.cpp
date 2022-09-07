#include <iostream>

int maxOddDivisor(int n, int currentNum) 
{
    if (currentNum == 1)
        return 1;
    if (n % currentNum == 0 && currentNum % 2 == 1)
        return currentNum;
    return maxOddDivisor(n, currentNum - 1);
}

int main() 
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    std::cout << maxOddDivisor(n, n/2) << "\n"; // Assumption: The largest odd divisor of n, not including n. 
    return 0;
}