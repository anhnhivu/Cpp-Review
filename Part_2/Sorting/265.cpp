#include <iostream>
#include <algorithm>

void printArr(int* arr, int len)
{
    for (int i = 0; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void printDescendingArray(int* arrA, uint8_t lenA, int* arrB, uint8_t lenB)
{
    int idxA = lenA - 1;
    int idxB = lenB - 1;
    int idxDescArr = 0;
    int* descArr = new int[long long(lenA) + lenB];

    while (idxA >= 0 && idxB >= 0)
    {
        if (arrA[idxA] >= arrB[idxB])
        {
            descArr[idxDescArr] = arrA[idxA];
            idxA--;
        }
        else
        {
            descArr[idxDescArr] = arrB[idxB];
            idxB--;
        }
        idxDescArr++;
    }

    while (idxA >= 0)
    {
        if (idxDescArr < lenA + lenB)
            descArr[idxDescArr] = arrA[idxA];
        idxA--;
        idxDescArr++;
    }

    while (idxB >= 0)
    {
        if (idxDescArr < lenA + lenB)
            descArr[idxDescArr] = arrB[idxB];
        idxB--;
        idxDescArr++;
    }

    printArr(descArr, lenA + lenB);

    if (descArr != nullptr)
        delete[] descArr;
    descArr = nullptr;
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

    printDescendingArray(arrA, lenA, arrB, lenB);

    if (arrA != nullptr)
        delete[] arrA;
    arrA = nullptr;

    if (arrB != nullptr)
        delete[] arrB;
    arrB = nullptr;

    return 0;
}