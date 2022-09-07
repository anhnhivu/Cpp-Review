#include <iostream>

void inputArray(double* arr, int& len)
{
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < len; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

void printArray(double* arr, int& len) 
{
    for (int i = 0; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int lenA;
    std::cout << "Enter length of your array A: ";
    std::cin >> lenA;
    double* arrA = new double[lenA];
    inputArray(arrA, lenA);

    int lenB = 0;
    for (int i = 0; i < lenA; i++)
        if (arrA[i] < 0)
            lenB++;

    double* arrB = new double[lenB];
    int indexB = 0;
    for (int i = 0; i < lenA; i++)
        if (arrA[i] < 0)
        {
            arrB[indexB] = arrA[i];
            indexB++;
        }
    std::cout << "Array B only contains negative values of array B: ";
    printArray(arrB, lenB);

    if (arrA != nullptr)
        delete[] arrA;
    arrA = nullptr;

    if (arrB != nullptr)
        delete[] arrB;
    arrB = nullptr;

    return 0;
}