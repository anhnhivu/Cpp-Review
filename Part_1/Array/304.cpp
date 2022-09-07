#include <iostream>

void segmentHasSumEqualsM(int *arr, int lenArr, int m) 
{
    int indexLeft = 0;
    int indexRight = lenArr - 1;
    int sumSegment = 0;
    bool foundSegment = false;

    for (int i = 0; i < lenArr && !foundSegment; i++) 
    {
        sumSegment += arr[i];
        indexRight = i;
        while (sumSegment > m) 
        {
            sumSegment -= arr[indexLeft];
            indexLeft++;
        }
        if (sumSegment == m) 
            foundSegment = true;
    }
    if (foundSegment) 
    {
        std::cout << "Found segment: [";
        for (int i = indexLeft; i < indexRight; i++) 
            std::cout << arr[i] << ", ";
        std::cout << arr[indexRight] << "].\n";
        return;
    }
    
    std::cout << "No segment found.\n";
}

int main() 
{
    int lenArr;
    std::cout << "Enter the length of your array: ";
    std::cin >> lenArr;

    int *arr = new int[lenArr];
    std::cout << "Enter the numbers in the array: \n";
    for (int i = 0; i < lenArr; i++) 
    {
        std::cout << i + 1 << ": ";
        std::cin >> arr[i];
    }

    int m;
    std::cout << "Enter a number M: ";
    std::cin >> m;

    segmentHasSumEqualsM(arr, lenArr, m);
    
    if (arr != nullptr)
        delete[] arr;
    arr = nullptr;
    return 0;
}