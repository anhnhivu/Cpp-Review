#include <iostream>

int sumOfEvenNumbers(int arr[], int lenArr, int sum) 
{
    if (lenArr == 0) 
        return sum;
    if (arr[lenArr - 1] % 2 == 0)
        sum += arr[lenArr - 1];
    return sumOfEvenNumbers(arr, lenArr - 1, sum);
}

int main() 
{
    int lenArr;
    std::cout << "Enter length of your array: ";
    std::cin >> lenArr;

    int *arr = new int[lenArr];
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < lenArr; i++) 
    {
        std::cout << i + 1 << ": ";
        std::cin >> arr[i];
    }

    std::cout << sumOfEvenNumbers(arr, lenArr, 0);
    
    if (arr != nullptr)
        delete [] arr;
    arr = nullptr;

    return 0;
}