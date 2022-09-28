#pragma once

class BigInteger
{
private:
    unsigned char bigint[16];
    void clear();

public:
    BigInteger();
    BigInteger(std::string str);
    BigInteger(const BigInteger &another);

    unsigned char* getValue();
    unsigned char getChar(const int& indexOfArray);
    void setBit(const int& indexOfArray, const int& indexInArray); // maybe not used
    void setChar(const int& indexOfArray, char value);

    void strToBigInt(std::string str);
    std::string bigIntToStr();
    bool isNegative() const;

    // Operator Overloading
    BigInteger operator + (const BigInteger& another);
    BigInteger operator - (const BigInteger& another);
    BigInteger operator * (const BigInteger& another);
    BigInteger operator / (const BigInteger& another);

    BigInteger operator << (const int &number);

    bool operator < (const BigInteger &another);
    bool operator > (const BigInteger &another);
    bool operator == (const BigInteger &another);
    bool operator != (const BigInteger &another);

    ~BigInteger();
};

// Read and write one big integer from console
BigInteger readConsole();
void writeConsole(BigInteger number);

// Read and write multiple big integers from text file
void readTextFile(const std::string& filename, BigInteger* listOfBigInt, const int& sizeOfList);
void writeTextFile(const std::string& filename, BigInteger* listOfBigInt, const int& sizeOfList);

// Read and write multiple big integers from binary file
void readBinaryFile(const std::string& filename, BigInteger* listOfBigInt, const int& sizeOfList, bool littleEndian = false);
void writeBinaryFile(const std::string& filename, BigInteger* listOfBigInt, const int& sizeOfList, bool littleEndian = false);

// Helper functions
BigInteger twosComplement(const BigInteger& another);