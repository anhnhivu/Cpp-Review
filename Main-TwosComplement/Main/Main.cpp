#include <iostream>
#include <bitset>

int main()
{
    unsigned char arr[10] = { 0, 1, 2, 126, 127, 128, 129, 130, 254, 255 };

    // Invert all bits
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            arr[i] ^= (1 << j);
        }
    }

    // Add one 
    for (int i = 0; i < 10; i++)
    {
        bool carry = 1;
        for (int j = 0; j < 8; j++)
        {
            if (carry == 1)
            {
                // if 0 + carry(1) = 1 -> carry = 0 
                if ((arr[i] & (1 << j)) == 0) 
                    carry = 0;
                arr[i] ^= (1 << j);
            }
        }
    }

    // For printing the results only
    for (int i = 0; i < 10; i++)
    {
        std::bitset<8> tmp(arr[i]);
        std::cout << tmp << "\n";
    }
    std::cout << "\n";

    return 0;
}

