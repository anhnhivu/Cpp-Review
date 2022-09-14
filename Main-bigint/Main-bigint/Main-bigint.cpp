#include <iostream>
#include <fstream>

#include <string>
#include <vector>
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

void twosComplement(unsigned char& binary, bool &flip)
{
    for (int j = 0; j < 8; j++)
    {
        if (flip)
            binary ^= (1 << j);
        else if (binary & (1 << j))
            flip = true;
    }
}

class BigInteger
{
    unsigned char bigint[16];

public:

    BigInteger() { clear(); }

    BigInteger(std::string str)
    {
        clear();
        strToBigInt(str);
    }

    void strToBigInt(std::string str)
    {
        int index = 127;
        bool negative = false;

        if (str[0] == '-')
        {
            str.erase(str.begin());
            negative = true;
        }       

        while (str != "0")
        {
            if (index < 0)
            {
                std::cout << "overflow  " << str << " " << index << "\n\n";
                overflowWarning();
                return;
            }

            if (str[str.size() - 1] % 2 == 1) // str[i] % 2 == (str[i] - '0') % 2
                bigint[index / 8] ^= (1 << ((127 - index) % 8));
            index--;

            str = divisionBy2(str);
        }

        if (negative)
        {
            bool flip = false;
            for (int i = 15; i >= 0; i--)
                twosComplement(bigint[i], flip);
        }
            
    }

    std::string bigIntToStr()
    {
        std::string strResult = "";
        int index = 0;
        bool negative = (bigint[0] & (1 << 7));

        if (negative)
        {
            bool flip = false;
            for (int i = 15; i >= 0; i--)
                twosComplement(bigint[i], flip);
        }

        while (index < 128) // 0 -> 127
        {
            strResult = multiplyBy2(strResult, bigint[index / 8] & (1 << ((127 - index) % 8)));
            index++;
        }

        if (negative)
            strResult = '-' + strResult;

        return strResult;
    }

    void clear()
    {
        for (int i = 0; i < 16; i++)
            bigint[i] = 0;
    }

    void overflowWarning()
    {
        std::cout << "Error: the number you entered is out of range.\n";
        clear();
    }

    void readConsole()
    {
        std::string str;
        std::cout << "Enter a big integer: ";
        std::cin >> str;
        strToBigInt(str);
    }

    void writeConsole()
    {
        std::cout << bigIntToStr() << "\n\n";
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

std::vector<BigInteger> readTextFile(const std::string &filename)
{
    std::ifstream textFile(filename);
    std::string line;

    std::vector<BigInteger> listOfBigInt;
    listOfBigInt.clear();

    if (textFile.is_open())
    {
        while (getline(textFile, line))
        {
            //std::cout << line << "\n";
            BigInteger tmp = BigInteger(line);
            listOfBigInt.push_back(tmp);
        }
    }

    textFile.close();
    return listOfBigInt;
}

void writeTextFile(std::vector<BigInteger> &listOfBigInt, const std::string& filename)
{
    std::ofstream textFile;
    textFile.open(filename, std::ios::out | std::ios::trunc);

    for (int i = 0; i < listOfBigInt.size(); i++)
        textFile << listOfBigInt[i].bigIntToStr() << "\n";

    textFile.close();
}

void rwConsole()
{
    // Read and write value with console
    BigInteger bigInt2;
    bigInt2.readConsole();
    bigInt2.writeConsole();
}

void rwTextFile()
{
    // Read and write value with text file
    std::vector<BigInteger> listOfBigInt = readTextFile("test.txt");
    writeTextFile(listOfBigInt, "outputTextFile.txt");
}

int main()
{
    // rwConsole();

    // rwTextFile();

    return 0;
}
