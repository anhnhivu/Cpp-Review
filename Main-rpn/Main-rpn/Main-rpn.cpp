#include <iostream>
#include <fstream>

#include <math.h>
#include <string>
#include <stack>
#include <queue>

const auto PLUS = '+';
const auto MINUS = '-';
const auto MUL = '*';
const auto DIVIDE = '/';
const auto POWER = '^';

bool isOperator(const char &currentOperator)
{
    return currentOperator == PLUS || currentOperator == MINUS || 
           currentOperator == MUL || currentOperator == DIVIDE || currentOperator == POWER;
}

void getTopOperator(std::string &postfix, const std::stack<char> &operators)
{
    postfix += operators.top();
    postfix += ' ';
}

std::string infixToPostfix(const std::string& infix)
{
    std::cout << infix << "\n";
    std::string postfix = "";

    std::stack<char> operators;
    int brackets = 0;

    for (int i = 0; i < infix.size(); i++)
    {        
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix += infix[i];
            if (i == infix.size() - 1 || infix[i + 1] < '0' || infix[i + 1] > '9')
                postfix += ' ';      
        }
        else if (!operators.empty() && (infix[i] == ')' || isOperator(infix[i])))
        {
            if (infix[i] == ')' && brackets > 0)
            {
                getTopOperator(postfix, operators);
                operators.pop();
                brackets--;
            }
            if (!operators.empty() && (infix[i] == MUL || infix[i] == DIVIDE || infix[i] == POWER) && (operators.top() == MUL || operators.top() == DIVIDE || infix[i] == POWER))
            {
                getTopOperator(postfix, operators);
                operators.pop();
            }
            if (brackets == 0 && !operators.empty() && (operators.top() == MUL || operators.top() == DIVIDE || infix[i] == POWER))
            {
                getTopOperator(postfix, operators);
                operators.pop();
            }
            if (!operators.empty() && (infix[i] == PLUS || infix[i] == MINUS) && (operators.top() == PLUS || operators.top() == MINUS))
            {
                getTopOperator(postfix, operators);
                operators.pop();
            }
        }
        if (isOperator(infix[i]))
            operators.push(infix[i]);
        if (infix[i] == '(')
            brackets++;
    }

    while (!operators.empty())
    {
        getTopOperator(postfix, operators);
        operators.pop();
    }
    return postfix;
}

int calculatePostfix(const std::string &postfix)
{
    std::stack<int> operands;
    int number = 0;

    for (int i = 0; i < postfix.size(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            number = number * 10 + (postfix[i] - '0');
            if (i == postfix.size() - 1 || postfix[i + 1] == ' ')
            {
                operands.push(number);
                number = 0;
            }
        }
          
        if (isOperator(postfix[i]) && operands.size() >= 2)
        {
            int firstNum = 0;
            int secondNum = 1;
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

            if (postfix[i] == PLUS)
                operands.push(firstNum + secondNum);
            else if (postfix[i] == MINUS)
                operands.push(firstNum - secondNum);
            else if (postfix[i] == MUL)
                operands.push(firstNum * secondNum);
            else if (postfix[i] == DIVIDE)
                operands.push(firstNum / secondNum);
            else if (postfix[i] == POWER)
                operands.push((int)pow(firstNum, secondNum)); 

            std::cout << operands.top() << "\n";
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
            calculatePostfix(infixToPostfix(line));
    }

    inputFile.close();

    return 0;
}
