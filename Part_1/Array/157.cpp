#include <iostream>

int MAX_INTEGER = 2147483647;
int MIN_INTEGER = -2147483648;

void findSegment(int *arr, int n) 
{
    int minNumber = MAX_INTEGER;
    int maxNumber = MIN_INTEGER;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < minNumber) 
            minNumber = arr[i];
        if (arr[i] > maxNumber) 
            maxNumber = arr[i];
    }
    
    std::cout << "The segment that contains all values in the array: [" << minNumber << ", " << maxNumber << "].\n";
}

int main() 
{
    int n;
    std::cout << "Enter length of your array: ";
    std::cin >> n;

    if (n < 1) 
    {
        std::cout << "Not valid.\n";
        return 0;
    }

    int *arr = new int[n];

    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < n; i++) 
    {
        std::cout << i + 1 << ": ";
        std::cin >> arr[i];
    }

    findSegment(arr, n);

    delete[] arr;
    return 0;
}