#include <iostream>
#include <set>

bool checkAinB(int* arrA, int lenA, int* arrB, int lenB)
{
    std::set<int> valuesInB;
    for (int i = 0; i < lenB; i++)
        valuesInB.insert(arrB[i]);

    for (int i = 0; i < lenA; i++)
        if (valuesInB.insert(arrA[i]).second)
            return false;

    return true;
}

void inputArray(int* arr, int& len)
{
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < len; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

int main()
{
    int lenA;
    std::cout << "Enter length of your array A: ";
    std::cin >> lenA;
    int *arrA = new int[lenA];
    inputArray(arrA, lenA);

    int lenB;
    std::cout << "Enter length of your array B: ";
    std::cin >> lenB;
    int *arrB = new int[lenB];
    inputArray(arrB, lenB);

    if (checkAinB(arrA, lenA, arrB, lenB))
        std::cout << "Every value in array A exists in array B.\n";
    else
        std::cout << "Not all value in array A exists in array B.\n";

    if (arrA != nullptr)
        delete[] arrA;
    arrA = nullptr;
    if (arrB != nullptr)
        delete[] arrB;
    arrB = nullptr;

    return 0;
}