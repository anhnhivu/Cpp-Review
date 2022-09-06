#include <iostream>

int isSymmetrical(int n) 
{
    int reverseNumber = 0;
    int tmpOriginalNumber = n;

    while (tmpOriginalNumber > 0) 
    {
        reverseNumber = reverseNumber * 10 + (tmpOriginalNumber % 10);
        tmpOriginalNumber /= 10;
    }

    return reverseNumber == n;
}

int main() 
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (isSymmetrical(n))
        std::cout << n << " is a symmetrical number.\n";
    else
        std::cout << n << " is not a symmetrical number.\n";

    return 0;
}