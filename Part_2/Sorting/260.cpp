#include <iostream>
#include <algorithm>

bool checkPermutation(int *arrA, int *arrB, int len)
{
    std::sort(arrA, arrA + len);
    std::sort(arrB, arrB + len);

    for (int i = 0; i < len; i++)
    {
        if (arrA[i] != arrB[i])
            return false;
    }
    return true;
}

int main()
{
    int lenA;
    std::cout << "Enter the length of your array A: ";
    std::cin >> lenA;

    int* arrA = new int[lenA];
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < lenA; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin >> arrA[i];
    }

    int lenB;
    std::cout << "Enter the length of your array B: ";
    std::cin >> lenB;

    int* arrB = new int[lenB];
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < lenB; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin >> arrB[i];
    }

    if (lenA != lenB)
        std::cout << "a is not a permutation of b\n";
    else if (checkPermutation(arrA, arrB, lenA))
        std::cout << "a is a permutation of b\n";
    else 
        std::cout << "a is not a permutation of b\n";

    if (arrA != nullptr)
        delete[] arrA;
    arrA = nullptr;

    if (arrB != nullptr)
        delete[] arrB;
    arrB = nullptr;

    return 0;
}