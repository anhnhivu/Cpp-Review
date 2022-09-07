#include <iostream>
#include <set>

class Matrix
{
    double** matrix;
    int row;
    int column;

public:
    Matrix(int a_row, int a_column)
    {
        row = a_row;
        column = a_column;

        matrix = new double* [row];
        for (int i = 0; i < row; i++)
            matrix[i] = new double[column];
    }

    void input() 
    {
        std::cout << "Type the values in the matrix: ";

        for (int i = 0; i < row; i++) 
        {
            std::cout << "Line " << i << ": \n";
            for (int j = 0; j < column; j++)
                std::cin >> matrix[i][j];
        }
    }

    void print()
    {
        std::cout << "\nPrint Matrix: \n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    int numberOfValues() 
    {
        std::set<double> setOfValues;
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                setOfValues.insert(matrix[i][j]);
            //     Alternative: 
            //     auto [iterator,success] = setOfValues.insert(matrix[i][j]);
            //     if (success)
            //         cnt++;

        return setOfValues.size();
    }


    ~Matrix()
    {
        for (int i = 0; i < row; i++)
            if (matrix[i] != nullptr)
                delete[] matrix[i];
        
        if (matrix != nullptr)
            delete[] matrix;
    }
};

int main() 
{
    int row;
    int column;
    
    try
    {
        std::cin.exceptions(std::istream::failbit);
        std::cout << "row of matrix: ";
        std::cin >> row;
        std::cout << "column of matrix: ";
        std::cin >> column;
    }
    catch (const std::ios::failure &)
    {
        std::cout << "Not a valid positive integer";
    }


    Matrix matrix(row, column);
    matrix.input();
    matrix.print();

    std::cout << "Number of different values in this matrix is: " << matrix.numberOfValues() << ".\n";
    
    return 0;
}