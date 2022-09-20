#include <string>
#include "calculate.h"

std::string divisionBy2(const std::string& number)
{
    std::string ans = "";

    if (number[0] >= '2')
        ans += (((number[0] - '0') / 2) + '0');

    int remainder = number[0] % 2;

    for (int i = 1; i < number.size(); i++)
    {
        ans += (((number[i] - '0' + 10 * remainder) / 2) + '0');
        remainder = number[i] % 2; // number[i] % 2 == (number[i] - '0') % 2
    }

    if (ans.size() == 0)
        return "0";

    return ans;
}

std::string multiplyBy2(const std::string& number, bool carry)
{
    if (number == "0")
        return "0";

    std::string ans = "";

    for (int i = number.size() - 1; i >= 0; i--)
    {
        int digit = number[i] - '0';
        char newDigit = '0' + ((digit * 2 + carry) % 10);
        if (digit * 2 + carry >= 10)
            carry = 1;
        else
            carry = 0;
        ans = newDigit + ans;
    }

    if (carry)
        ans = '1' + ans;

    return ans;
}

void twosComplement(unsigned char& binary, bool& flip)
{
    for (int j = 0; j < 8; j++)
    {
        if (flip)
            binary ^= (1 << j);
        else if (binary & (1 << j))
            flip = true;
    }
}