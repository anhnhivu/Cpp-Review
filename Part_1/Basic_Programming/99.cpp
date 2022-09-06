#include <iostream>

void swapNumIfSmaller(double &numA, double &numB) 
{
    if (numA < numB) 
    {
        double tmp = numA;
        numA = numB;
        numB = tmp;
    }
}

void printThreeNum() 
{
    double num1, num2, num3;
    std::cout << "Enter the 1st number: ";
    std::cin >> num1;
    std::cout << "Enter the 2nd number: ";
    std::cin >> num2;
    std::cout << "Enter the 3rd number: ";
    std::cin >> num3;

    swapNumIfSmaller(num2, num1);
    swapNumIfSmaller(num3, num2);
    swapNumIfSmaller(num2, num1);

    std::cout << "In ascending order: " << num1 << " " << num2 << " " << num3 << "\n.";
}

int main() 
{
    printThreeNum();
    return 0;
}