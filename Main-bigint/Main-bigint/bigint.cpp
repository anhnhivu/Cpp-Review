#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <bitset>

#include "bigint.hpp"
#include "calculate.hpp"

BigInteger::BigInteger()
{
    clear();
}

BigInteger::BigInteger(std::string str)
{
    clear();
    strToBigInt(str);
}

BigInteger::BigInteger(const BigInteger &another)
{
    clear();
    for (int i = 0; i < 16; i++)
        bigint[i] = const_cast<BigInteger&>(another).getChar(i);
}

unsigned char* BigInteger::getValue()
{
    return bigint;
}

unsigned char BigInteger::getChar(const int& indexOfArray)
{
    if (indexOfArray < 0 || indexOfArray >= 16)
    {
        std::cout << "Error getChar(): parameter out of range 0-15.\n";
        return 0;
    }
    return bigint[indexOfArray];
}

void BigInteger::setBit(const int &indexOfArray, const int &indexInArray)
{
    if (indexOfArray < 0 || indexOfArray >= 16)
    {
        std::cout << "Error setBit(): first parameter out of range 0-15.\n";
        return;
    }
    if (indexInArray < 0 || indexInArray >= 8)
    {
        std::cout << "Error setBit(): second parameter out of range 0-7.\n";
        return;
    }
    bigint[indexOfArray] ^= (1 << (7 - indexInArray));
}

void BigInteger::setChar(const int& indexOfArray, char value)
{
    if (indexOfArray < 0 || indexOfArray >= 16)
    {
        std::cout << "Error setChar(): parameter out of range 0-15.\n";
        return;
    }
    bigint[indexOfArray] = value;
}

void BigInteger::clear()
{
    for (int i = 0; i < 16; i++)
        bigint[i] = 0;
}

void BigInteger::overflowWarning()
{
    std::cout << "Error: the number you entered is out of range.\n";
    clear();
}

bool BigInteger::isNegative()
{
    return bigint[0] & (1 << 7);
}

bool BigInteger::isNegative(BigInteger number)
{
    return number.getChar(0) & (1 << 7);
}

void BigInteger::strToBigInt(std::string str)
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

std::string BigInteger::bigIntToStr()
{
    std::string strResult = "";
    int index = 0;
    bool negative = this->isNegative();

    if (negative)
    {
        bool flip = false;
        for (int i = 15; i >= 0; i--)
            twosComplement(bigint[i], flip);
    }

    while (index < 128) // 0 -> 127
    {
        bool carry = bigint[index / 8] & (1 << ((127 - index) % 8));
        strResult = multiplyBy2(strResult, carry);
        index++;
    }

    if (negative)
        strResult = '-' + strResult;

    if (strResult == "")
        return "0";
    
    return strResult;
}

BigInteger twosComplement(const BigInteger& another)
{
    BigInteger number = BigInteger(another);
    bool flip = false;
    for (int i = 15; i >= 0; i--)
    {
        unsigned char value = number.getChar(i);
        twosComplement(value, flip);
        number.setChar(i, value);
    }
    return number;
}

bool BigInteger::operator < (const BigInteger &another)
{
    if (*this == another)
        return false;

    bool firstNumberIsNegative = this->isNegative();
    bool secondNumberIsNegative = isNegative(another);

    // Different signs
    if (firstNumberIsNegative ^ secondNumberIsNegative) // one number is negative, one number is positive
        return firstNumberIsNegative && (!secondNumberIsNegative);

    // Both negative numbers
    if (firstNumberIsNegative & secondNumberIsNegative)
    {
        BigInteger firstNumber(twosComplement(*this));
        BigInteger secondNumber(twosComplement(another));

        for (int i = 0; i < 16; i++)
            if (secondNumber.getChar(i) > firstNumber.getChar(i))
                return false;
        return true;
    }

    // Both positive numbers
    for (int i = 0; i < 16; i++)
        if (bigint[i] > another.bigint[i])
            return false;
    return true;
}

bool BigInteger::operator > (BigInteger const& another)
{
    return !(*this == another) && !(*this < another);
}

bool BigInteger::operator == (BigInteger const& another)
{
    for (int i = 0; i < 16; i++)
        if (bigint[i] != another.bigint[i])
            return false;
    return true;
}

bool BigInteger::operator != (BigInteger const& another)
{
    for (int i = 0; i < 16; i++)
        if (bigint[i] != another.bigint[i])
            return true;
    return false;
}
    
BigInteger::~BigInteger() 
{ 
    clear(); 
}

BigInteger readConsole()
{
    std::string str;
    std::cout << "Enter a big integer: ";
    std::cin >> str;

    BigInteger number(str);
    return number;
}

BigInteger BigInteger::operator + (const BigInteger& another)
{
    BigInteger sum("0");
    bool carry = 0;

    bool firstNumberIsNegative = this->isNegative();
    bool secondNumberIsNegative = isNegative(another);

    for (int i = 15; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            bool firstBit = bigint[i] & (1 << j);
            bool secondBit = another.bigint[i] & (1 << j);

            if (!carry)
            {
                if (firstBit ^ secondBit)
                    sum.setBit(i, 7 - j);
                if (firstBit & secondBit)
                    carry = 1;
            } else {
                if (!(firstBit ^ secondBit))
                    sum.setBit(i, 7 - j);
                if (!(firstBit | secondBit))
                    carry = 0;
            }
        }
    }

    if (!(firstNumberIsNegative ^ secondNumberIsNegative) && (firstNumberIsNegative ^ isNegative(sum)))
    {
        std::cout << "+/- operator: Big Integer Overflow.\n";
        return BigInteger("0");
    }

    return sum;
}

BigInteger BigInteger::operator - (const BigInteger& another)
{
    return (*this + twosComplement(another));
}

BigInteger BigInteger::operator << (const int& number)
{
    BigInteger result("0");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int ii = i + ((j + number) / 8);
            int jj = 7 - ((j + number) % 8);

            if (ii < 16 && bigint[ii] & (1 << jj))
                result.setBit(i, j);
        }
    }
    return result;
}

BigInteger BigInteger::operator * (const BigInteger& another)
{
    BigInteger product("0");
    
    BigInteger firstNumber(*this);
    BigInteger secondNumber(another);

    bool firstNumberIsNegative = this->isNegative();
    bool secondNumberIsNegative = isNegative(another);

    if (firstNumberIsNegative)
        firstNumber = BigInteger("0") - firstNumber;
    if (secondNumberIsNegative)
        secondNumber = BigInteger("0") - secondNumber;

    for (int i = 15; i >= 0; i--)
        for (int j = 0; j < 8; j++)
            if (secondNumber.bigint[i] & (1 << j))
                product = product + (firstNumber << (8 * (15 - i) + j));


    if (firstNumberIsNegative ^ secondNumberIsNegative)
        product = twosComplement(product);

    return product;
}

BigInteger BigInteger::operator / (const BigInteger& another)
{
    BigInteger quotient(*this);
    BigInteger secondNumber(another);

    bool firstNumberIsNegative = this->isNegative();
    bool secondNumberIsNegative = isNegative(another);

    if (firstNumberIsNegative)
        quotient = BigInteger("0") - quotient;
    if (secondNumberIsNegative)
        secondNumber = BigInteger("0") - secondNumber;

    int digitsInSecondNumber = 0;
    int ii = 15;
    int jj = 7; 

    for (int i = 0; i < 15; i++)
        for (int j = 8; j >= 0; j--)
            if (secondNumber.bigint[i] & (1 << j))
            {
                ii = i;
                jj = j;
                digitsInSecondNumber = 128 - (8 * i + 7 - j);
                break;
            }

    for (int i = ii; i >= 0; i--)
        for (int j = jj; j >= 0 && digitsInSecondNumber; j--)
        {
            if (secondNumber.bigint[i] & (1 << j))
                quotient = quotient - (secondNumber << (8 * (15 - i) + j - digitsInSecondNumber));
            digitsInSecondNumber--;
        }
            
    if (firstNumberIsNegative ^ secondNumberIsNegative)
        quotient = twosComplement(quotient);

    return quotient;
}

void writeConsole(BigInteger number)
{
    std::cout << number.bigIntToStr() << "\n";
}
 
void readTextFile(const std::string& filename, BigInteger* listOfBigInt, const int &sizeOfList)
{
    std::ifstream textFile(filename);
    std::string line;

    if (textFile.is_open())
    {
        getline(textFile, line); // skip first line, already read in other function
        for (int i = 0; i < sizeOfList; i++)
            if (getline(textFile, line))
                listOfBigInt[i] = BigInteger(line);
    }
    else 
        std::cout << "Cannot read text file: " << filename << "\n";
    textFile.close();
}

void writeTextFile(const std::string& filename, BigInteger* listOfBigInt, const int &sizeOfList)
{
    std::ofstream textFile;
    textFile.open(filename, std::ios::out | std::ios::trunc);

    textFile << sizeOfList << "\n";
    for (int i = 0; i < sizeOfList; i++)
        textFile << listOfBigInt[i].bigIntToStr() << "\n";

    textFile.close();
}

void readBinaryFile(const std::string& filename, BigInteger* listOfBigInt, const int& sizeOfList, bool littleEndian)
{
    std::ifstream binaryFile(filename, std::ios::binary);
    uint8_t skip;

    if (binaryFile.is_open())
    {
        binaryFile.read((char*)(&skip), sizeof(uint8_t)); // skip first line, already read in other function
        for (int k = 0; k < sizeOfList; k++)
        {
            BigInteger number;
            for (int i = 0; i < 16; i++)
            {
                char value;
                binaryFile.read((char*)(&value), sizeof(char));
                if (binaryFile.fail())
                {
                    std::cout << "Error reading binary file.\n";
                    return;
                }
                if (littleEndian)
                    number.setChar(15 - i, value);
                else
                    number.setChar(i, value);
            }
            listOfBigInt[k] = number;
        }
    }
    else 
        std::cout << "readBinaryFile(): Cannot read binary file: " << filename << "\n";
    binaryFile.close();
}

void writeBinaryFile(const std::string& filename, BigInteger* listOfBigInt, const int& sizeOfList, bool littleEndian)
{
    std::ofstream binaryFile;
    binaryFile.open(filename, std::ios::out | std::ios::binary | std::ios::trunc);

    if (binaryFile.is_open())
    {
        binaryFile.write((char*)(&sizeOfList), sizeof(uint8_t)); // skip first line, already read in other function
        for (int k = 0; k < sizeOfList; k++)
        {
            for (int i = 0; i < 16; i++)
            {
                char value;
                if (littleEndian)
                    value = listOfBigInt[k].getChar(15 - i);
                else
                    value = listOfBigInt[k].getChar(i);
                binaryFile.write((char*)(&value), sizeof(char));
                if (binaryFile.fail())
                {
                    std::cout << "Error reading binary file.\n";
                    return;
                }
                
            }
        }
    }
    else
        std::cout << "writeBinaryFile(): Cannot write binary file: " << filename << "\n";
    binaryFile.close();
}