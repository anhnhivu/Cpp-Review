#include <iostream>

class SquareMatrix
{
    int** sqMatrix;
    int length;

    bool checkSumOfRows()
    {
        int sumOfFirstRow = 0;
        for (int i = 0; i < length; i++) 
            sumOfFirstRow += sqMatrix[0][i];

        int sumOfSubsequentRow = 0;
        for (int i = 1; i < length; i++)
        {
            sumOfSubsequentRow = 0;
            for (int j = 0; j < length; j++)
                sumOfSubsequentRow += sqMatrix[i][j];
            
            if (sumOfSubsequentRow != sumOfFirstRow)
                return false;
        }

        return true;
    }

    bool checkSumOfColumns()
    {
        int sumOfFirstColumn = 0;
        for (int i = 0; i < length; i++)
            sumOfFirstColumn += sqMatrix[i][0];

        int sumOfSubsequentColumn = 0;
        for (int j = 1; j < length; j++)
        {
            sumOfSubsequentColumn = 0;
            for (int i = 0; i < length; i++)
                sumOfSubsequentColumn += sqMatrix[i][j];
            
            if (sumOfSubsequentColumn != sumOfFirstColumn)
                return false;
        }

        return true;
    }

    bool checkSumOfDiagonals()
    {
        int sumMainDiagonal = 0;
        int sumSubDiagonal = 0;

        for (int i = 0; i < length; i++)
        {
            sumMainDiagonal += sqMatrix[i][i];
            sumSubDiagonal += sqMatrix[length - i - 1][i];
        }

        return sumMainDiagonal == sumSubDiagonal;
    }

public:
    SquareMatrix(int n)
    {
        sqMatrix = new int* [n];
        length = n;
        for (int i = 0; i < n; i++)
            sqMatrix[i] = new int[n];
    }

    void input() 
    {
        std::cout << "Type the values in the matrix: ";
        for (int i = 0; i < length; i++) 
        {
            std::cout << "Line " << i << ": \n";
            for (int j = 0; j < length; j++)
                std::cin >> sqMatrix[i][j];
        }
    }

    void print()
    {
        std::cout << "\nPrint Matrix: \n";
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
                std::cout << sqMatrix[i][j] << " ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    bool isSpecial() 
    {
        return checkSumOfRows() && checkSumOfColumns() && checkSumOfDiagonals();
    }

    ~SquareMatrix()
    {
        for (int i = 0; i < length; i++)
        {
            if (sqMatrix[i] != nullptr)
                delete[] sqMatrix[i];
            sqMatrix[i] = nullptr;
        }

        if (sqMatrix != nullptr)
            delete[] sqMatrix;
        sqMatrix = nullptr;
    }
};

int main() 
{
    int n;
    std::cout << "Size of matrix n x n: ";
    try
    {
        std::cin.exceptions(std::istream::failbit);
        std::cin >> n;
    }
    catch (const std::ios::failure &)
    {
        std::cout << "Not a valid positive integer";
    }

    SquareMatrix squareMatrix(n);
    squareMatrix.input();
    squareMatrix.print();

    if (squareMatrix.isSpecial())
        std::cout << "This matrix is a special matrix.\n";
    else
        std::cout << "This matrix is not a special matrix.\n";
    
    return 0;
}