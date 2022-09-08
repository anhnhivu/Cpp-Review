#include <iostream>
#include <fstream>

#include <math.h>
#include <string>
#include <stack>

int calculate(const std::string &infix)
{
    std::cout << infix << "\n";
    std::string postfix = "";

    std::stack<char> operators;

    // Convert from infix to postfix notation
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] >= 48 && infix[i] <= 57)
            postfix += infix[i];
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
            operators.push(infix[i]);
        if (infix[i] == ')' || i == infix.size() - 1)
            if (!operators.empty())
            {
                postfix += operators.top();
                operators.pop();
            }  
    }

    // Calculate the result from the postfix notation
    // Assume all numbers are 1-digit 

    std::stack<int> operands;

    for (int i = 0; i < postfix.size(); i++)
    {
        if (postfix[i] >= 48 && postfix[i] <= 57)
            operands.push(int(postfix[i]) - 48);
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            int firstNum;
            int secondNum;
            if (!operands.empty())
            {
                secondNum = operands.top();
                operands.pop();
            }
            if (!operands.empty())
            {
                firstNum = operands.top();
                operands.pop();
            }

            if (postfix[i] == '+')
                operands.push(firstNum + secondNum);
            if (postfix[i] == '-')
                operands.push(firstNum - secondNum);
            if (postfix[i] == '*')
                operands.push(firstNum * secondNum);
            if (postfix[i] == '/')
                operands.push(firstNum / secondNum);
            if (postfix[i] == '^')
                operands.push(pow(firstNum, secondNum));
        }
    }

    int result = 0;
    if (!operands.empty()) 
    {
        result = operands.top();
        operands.pop();
    }

    std::cout << "Postfix notation is: " << postfix << "\n";
    std::cout << "Result: " << result << "\n\n";
    return 0;
}

int main()
{
    std::ifstream inputFile("test.txt");
    std::string line;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
            calculate(line);
    }

    inputFile.close();

    return 0;
}
