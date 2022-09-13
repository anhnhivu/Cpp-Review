#include <iostream>
#include <bitset>

void twosComplement(unsigned char &binary)
{
    bool flip = false;

    for (int j = 0; j < 8; j++)
    {
        if (flip)
            binary ^= (1 << j);
        if (binary & (1 << j))
            flip = true;
    }
}

int main()
{
    unsigned char arr[10] = { 0, 1, 2, 126, 127, 128, 129, 130, 254, 255 };

    // Calculate 
    for (int i = 0; i < 10; i++)
        twosComplement(arr[i]);

    // For printing the results only
    for (int i = 0; i < 10; i++)
    {
        std::bitset<8> tmp(arr[i]);
        std::cout << tmp << "\n";
    }
    std::cout << "\n";

    return 0;
}
