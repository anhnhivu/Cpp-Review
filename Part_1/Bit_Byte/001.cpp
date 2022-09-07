#include <iostream>
#include <string>

std::string calculateTwosComplement(int num)
{
    std::string result = "11111111";
   
    // Convert to binary then invert it
    int idx = 7;
    while (num > 0)
    {
        if (num % 2 == 1)
            result[idx] = '0';
        idx--;
        num /= 2;
    }

    // Add one
    int carry = 1;
    for (int i = 7; i >= 0; i--)
    {
        if (result[i] == '1' && carry == 1)
            result[i] = '0';
        else if (result[i] == '0' && carry == 1)
        {
            result[i] = '1';
            carry = 0;
        }
    }

    return result;
}

int main()
{
    int arr[] = { 0, 1, 2, 126, 127, 128, 129, 130, 254, 255 };

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Two's complement of " << arr[i] << " is: ";
        std::cout << calculateTwosComplement(arr[i]) << "\n";
    }
    return 0;
}