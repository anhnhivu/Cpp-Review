#include <iostream>

void printArr(int arr[], int lenArr)
{
    for (int i = 0; i < lenArr; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int findCurrentMinValueIndex(int arr[], int currentIndex, int minValueIndex, int lenArr)
{
    if (currentIndex == lenArr)
        return minValueIndex;
    if (arr[currentIndex] < arr[minValueIndex])
        minValueIndex = currentIndex;
    return findCurrentMinValueIndex(arr, currentIndex + 1, minValueIndex, lenArr);
}

void sortArrWithRecursion(int arr[], int currentIndex, int lenArr)
{
    // Selection Sort
    if (currentIndex == lenArr)
        return;

    int tmpSwap = arr[currentIndex];
    int minValueIndex = findCurrentMinValueIndex(arr, currentIndex, currentIndex, lenArr);
    arr[currentIndex] = arr[minValueIndex];
    arr[minValueIndex] = tmpSwap;

    sortArrWithRecursion(arr, currentIndex + 1, lenArr);
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

    sortArrWithRecursion(arr, 0, lenArr);
    printArr(arr, lenArr);

    if (arr != nullptr)
        delete[] arr;
    arr = nullptr;

    return 0;
}