#include <iostream>
#include <fstream>
#include <string>

// Source: https://cplusplus.com/doc/tutorial/files/ 

int main()
{

    // Write 
    std::ofstream outputFile;
    outputFile.open("file_stream/output.txt", std::ios::out | std::ios::app);

    // also create a new file if not existed
    
    // ios::out = open for output operations
    // ios::app = all output operations are added to the end of the file
    // using <fstream> default mode parameter is ios::in | ios::out

    outputFile << "This is a new file: \n";
    outputFile << "Name: \n";
    outputFile << "Age: \n";

    // Read  
    std::ifstream inputFile ("file_stream/input.txt");
    std::string line;
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            std::cout << line << "\n";
        }
    }

    outputFile.close();
    inputFile.close();
    
    return 0;
}