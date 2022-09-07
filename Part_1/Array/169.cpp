#include <iostream>

int MAX_ODD_NUM = 2147483647;
int MIN_EVEN_NUM = -2147483648;

int maxEvenLessThanOdd(int arr[], int n) 
{
    int minOddNumber = MAX_ODD_NUM;
    int maxEvenNumber = MIN_EVEN_NUM;
    bool oddNumberExists = false;
    bool maxEvenNumberExists = false;

    for (int i = 0; i < n; i++) 
        if (arr[i] % 2 == 1)
        {
            if (!oddNumberExists)
                oddNumberExists = true;
            if (arr[i] < minOddNumber)
                minOddNumber = arr[i];
        }
    
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] % 2 == 0 && arr[i] >= maxEvenNumber && arr[i] < minOddNumber)
        {
            maxEvenNumberExists = true;
            maxEvenNumber = arr[i];
        }
    }

    if (!oddNumberExists || !maxEvenNumberExists)
        return -1;

    return maxEvenNumber;
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

    int result = maxEvenLessThanOdd(arr, n);

    if (result == -1) 
        std::cout << "There is no number satisfy the conditions.";
    else 
        std::cout << "The max even number that is smaller than all odd numbers in the array is: " << result << "\n";

    if (arr != nullptr)
        delete arr;
    arr = nullptr;
    return 0;
}