#include <iostream>
#include <algorithm>

void printArr(int arr[], int lenArr)
{
    for (int i = 0; i < lenArr; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void sortPositiveNumbers(int arr[], int lenArr)
{
    int* arrPositive = new int[lenArr];
    int lenArrPositive = 0;
    for (int i = 0; i < lenArr; i++)
    {
        if (arr[i] > 0)
        {
            arrPositive[lenArrPositive] = arr[i];
            lenArrPositive++;
        }
    }
    std::sort(arrPositive, arrPositive + lenArrPositive);

    int idxPostive = 0;
    for (int i = 0; i < lenArr; i++)
    {
        if (arr[i] > 0)
        {
            arr[i] = arrPositive[idxPostive];
            idxPostive++;
        }
    }
    printArr(arr, lenArr);
    if (arrPositive != nullptr)
        delete[] arrPositive;
    arrPositive = nullptr;
}

int main()
{
    int lenArr;
    std::cout << "Enter length of your array: ";
    std::cin >> lenArr;

    int* arr = new int[lenArr];
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < lenArr; i++) 
    {
        std::cout << i + 1 << ": ";
        std::cin >> arr[i];
    }

    sortPositiveNumbers(arr, lenArr);

    if (arr != nullptr)
        delete[] arr;
    arr = nullptr;
    return 0;
}