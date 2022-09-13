#include <iostream>
#include <string>
#include <math.h>
#include <bitset>

// Completed: read and write value with console

std::string divisionBy2(const std::string &number)
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

std::string multiplyBy2(const std::string &number, bool carry)
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

class BigInteger
{
    char bigint[16];

    void strToBigInt(std::string str)
    {
        int index = 127;
        while (str != "0")
        {
            if (str[str.size() - 1] % 2 == 1) // str[i] % 2 == (str[i] - '0') % 2
                bigint[index / 8] ^= (1 << ((127 - index) % 8));
            index--;
            str = divisionBy2(str);
        }
    }

    std::string bigIntToStr(const BigInteger &a_bigint)
    {
        std::string strResult = "";
        int index = 0;

        while (index < 128) // 0 -> 127
        {
            strResult = multiplyBy2(strResult, a_bigint.bigint[index / 8] & (1 << ((127 - index) % 8)));
            index++;
        }

        return strResult;
    }

    void clear()
    {
        for (int i = 0; i < 16; i++)
            bigint[i] = 0;
    }

public:

    BigInteger() { clear(); }

    void readConsole()
    {
        std::string str;
        std::cout << "Enter a big integer: ";
        std::cin >> str;
        strToBigInt(str);
    }

    void writeConsole()
    {
        for (int i = 0; i < 16; i++)
            //std::cout << bigint[i];
        {
            std::bitset<8> tmp(bigint[i]);
            std::cout << tmp << "\n";
        }

        std::cout << bigIntToStr(*this) << "\n";
        std::cout << "\n";
    }

    bool operator == (BigInteger const& obj)
    {
        for (int i = 0; i < 16; i++)
            if (bigint[i] != obj.bigint[i])
                return false;
        return true;
    }

    bool operator != (BigInteger const& obj)
    {
        for (int i = 0; i < 16; i++)
            if (bigint[i] != obj.bigint[i])
                return true;
        return false;
    }

    
    ~BigInteger() { clear(); }
};

int main()
{

    BigInteger bigInt2;
    bigInt2.readConsole();
    bigInt2.writeConsole();


    return 0;
}
