#include <iostream>
#include <fstream>

#include <math.h>
#include <string>
#include <vector>
#include <bitset>

#include "bigint.hpp"
#include "calculate.hpp"

void readWriteConsole()
{
    // Read and write value with console
    BigInteger bigInt2 = readConsole();
    writeConsole(bigInt2);
}

void readWriteTextFile(const std::string &inputFile, const std::string &outputFile)
{
    std::ifstream textFile(inputFile, std::ios::in);
    std::string line;
    if (textFile.is_open())
        getline(textFile, line);
    else
    {
        std::cout << "rwTextFile(): Cannot open file/ File does not exist.\n";
        return;
    }

    int numbersOfBigInt = stoi(line);
    textFile.close();

    // Read and write value with text file
    BigInteger* listOfBigInt = new BigInteger[numbersOfBigInt];
    readTextFile(inputFile, listOfBigInt, numbersOfBigInt);
    writeTextFile(outputFile, listOfBigInt, numbersOfBigInt);

    if (listOfBigInt != nullptr)
        delete[] listOfBigInt;
    listOfBigInt = nullptr;
}

void readWriteBinaryFile(const std::string& inputFile, const std::string& outputFile, bool littleEndian = false)
{
    std::ifstream binaryFile(inputFile, std::ios::binary);
    uint8_t numbersOfBigInt = 0;
    if (binaryFile.is_open())
        binaryFile.read((char*)(&numbersOfBigInt), sizeof(uint8_t));
    else
    {
        std::cout << "rwBinaryFile(): Cannot open file/ File does not exist.\n";
        return;
    }
    binaryFile.close();

    BigInteger* listOfBigInt = new BigInteger[numbersOfBigInt];
    readBinaryFile(inputFile, listOfBigInt, numbersOfBigInt, littleEndian);
    writeBinaryFile(outputFile, listOfBigInt, numbersOfBigInt, littleEndian);
}

int main()
{
    // readWriteConsole();

    readWriteTextFile("test/inputTextFile.txt", "test/outputTextFile.txt");

    // Big Endian
    // readWriteBinaryFile("test/inputBinaryFileBigEndian.bin", "test/outputBinaryFileBigEndian.bin");

    // Little Endian
    // readWriteBinaryFile("test/inputBinaryFileLittleEndian.bin", "test/outputBinaryFileLittleEndian.bin", true);

    BigInteger num1("60000");
    BigInteger num2("3000");

    std::cout << "num1 = ";
    writeConsole(num1); 
    std::cout << "num2 = ";
    writeConsole(num2); 


    std::cout << "\nnum1 == num2: " << (num1 == num2) << "\n";
    std::cout << "num1 != num2: " << (num1 != num2) << "\n";
    std::cout << "num1 < num2: " << (num1 < num2) << "\n";
    std::cout << "num1 > num2: " << (num1 > num2) << "\n\n";

    std::cout << "num1 + num2 = ";
    writeConsole(num1 + num2);
    std::cout << "num1 - num2 = ";
    writeConsole(num1 - num2);
    std::cout << "num1 * num2 = ";
    writeConsole(num1 * num2);
    std::cout << "num1 / num2 = ";
    writeConsole(num1 / num2);
    std::cout << "num1 << 2 = ";
    writeConsole(num1 << 2); 


    return 0;
}