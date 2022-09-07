#include <iostream>

void printArr(int arr[], int lenArr, int index) 
{
    if (index == lenArr) 
    {
        std::cout << "\n";
        return;
    }
    std::cout << arr[index] << " ";
    printArr(arr, lenArr, index + 1);
}

int main() 
{
    int lenArr;
    std::cout << "Enter length of your array: ";
    std::cin >> lenArr;

    int *arr = new int[lenArr];
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < lenArr; i++) {
        std::cout << i + 1 << ": ";
        std::cin >> arr[i];
    }

    std::cout << "Print array in correct order: "; // 718
    printArr(arr, lenArr, 0);

    if (arr != nullptr)
        delete [] arr;
    arr = nullptr;

    return 0;
}