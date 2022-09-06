#include <iostream>
#include <set>

class Matrix
{
    double** matrix;
    int length;
    int width;

public:
    Matrix(int a_length, int a_width)
    {
        length = a_length;
        width = a_width;

        matrix = new double* [length];
        
        for (int i = 0; i < length; i++)
        {
            matrix[i] = new double[width];
        }
    }

    void input() 
    {
        std::cout << "Type the values in the matrix: ";

        for (int i = 0; i < length; i++) 
        {
            std::cout << "Line " << i << ": \n";
            for (int j = 0; j < width; j++)
            {
                std::cin >> matrix[i][j];
            }
        }
    }

    void print()
    {
        std::cout << "\nPrint Matrix: \n";
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    int numberOfValues() 
    {
        int totalNumberOfValues = 0;

        std::set<double> setOfValues;
        std::set<double>::iterator it;

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (setOfValues.find(matrix[i][j]) == setOfValues.end())
                {
                    totalNumberOfValues++;
                    setOfValues.insert(matrix[i][j]);
                }
            }
        }

        return totalNumberOfValues;
    }


    ~Matrix()
    {
        for (int i = 0; i < length; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main() 
{
    int length;
    int width;
    
    try
    {
        std::cin.exceptions(std::istream::failbit);

        std::cout << "Length of matrix: ";
        std::cin >> length;
        std::cout << "Width of matrix: ";
        std::cin >> width;
    }
    catch (const std::ios::failure &)
    {
        std::cout << "Not a valid positive integer";
    }


    Matrix * matrix = new Matrix(length, width);
    matrix->input();
    matrix->print();

    std::cout << "Number of different values in this matrix is: " << matrix->numberOfValues() << ".\n";
    
    return 0;
}