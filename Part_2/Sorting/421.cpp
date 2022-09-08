#include <iostream>
#include <algorithm>

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
            std::cout << "Line " << i+1 << ": \n";
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

    void sortPositiveOnEdge()
    {
        int cntPositiveNumbersOnEdge = 0;
        int sizeOfArr = 2 * row + 2 * column - 4;
        double* arrPositiveNumbersOnEdge = new double[sizeOfArr];

        for (int j = 0; j < column - 1; j++)
            if (matrix[0][j] > 0)
            {
                arrPositiveNumbersOnEdge[cntPositiveNumbersOnEdge] = matrix[0][j];
                cntPositiveNumbersOnEdge++;
            }
        for (int i = 0; i < row - 1; i++)
            if (matrix[i][column - 1] > 0)
            {
                arrPositiveNumbersOnEdge[cntPositiveNumbersOnEdge] = matrix[i][column - 1];
                cntPositiveNumbersOnEdge++;
            }
        for (int j = 1; j < column; j++)
            if (matrix[row - 1][j] > 0)
            {
                arrPositiveNumbersOnEdge[cntPositiveNumbersOnEdge] = matrix[row - 1][j];
                cntPositiveNumbersOnEdge++;
            }
        for (int i = 1; i < row; i++)
            if (matrix[i][0] > 0)
            {
                arrPositiveNumbersOnEdge[cntPositiveNumbersOnEdge] = matrix[i][0];
                cntPositiveNumbersOnEdge++;
            }

        std::sort(arrPositiveNumbersOnEdge, arrPositiveNumbersOnEdge + cntPositiveNumbersOnEdge);

        int idxSortedArr = 0;
        for (int j = 0; j < column - 1; j++)
            if (matrix[0][j] > 0)
            {
                matrix[0][j] = arrPositiveNumbersOnEdge[idxSortedArr];
                idxSortedArr++;
            }
        for (int i = 0; i < row - 1; i++)
            if (matrix[i][column - 1] > 0)
            {
                matrix[i][column - 1] = arrPositiveNumbersOnEdge[idxSortedArr];
                idxSortedArr++;
            }
        for (int j = column - 1; j > 0; j--)
            if (matrix[row - 1][j] > 0)
            {
                matrix[row - 1][j] = arrPositiveNumbersOnEdge[idxSortedArr];
                idxSortedArr++;
            }
        for (int i = row - 1; i > 0; i--)
            if (matrix[i][0] > 0)
            {
                matrix[i][0] = arrPositiveNumbersOnEdge[idxSortedArr];
                idxSortedArr++;
            }
        
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
    catch (const std::ios::failure&)
    {
        std::cout << "Not a valid positive integer";
    }


    Matrix matrix(row, column);
    matrix.input();
    matrix.print();

    matrix.sortPositiveOnEdge();

    std::cout << "Matrix after sorting the postive numbers on edge:\n";
    matrix.print();

    return 0;
}