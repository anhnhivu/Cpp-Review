#include <iostream>

int getMissingNumber(int arr[], int n)
{
    // XOR all the elements in array
    int a = arr[0];

    // XOR all the elements from 1 to n+1
    int b = 1;

    for (int i = 1; i < n; i++)
        a = a ^ arr[i];

    for (int i = 2; i <= n + 1; i++)
        b = b ^ i;

    return a ^ b;
}

int main()
{
    int n;
    std::cout << "Enter number N: ";
    std::cin >> n;

    int len = n - 1;
    int *arr = new int[len];
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin >> arr[i];
    }

    int missingNumber = getMissingNumber(arr, n - 1);
    std::cout << "The missing number is: " << missingNumber << "\n";

    if (arr != nullptr)
        delete[] arr;
    arr = nullptr;
    return 0;
}