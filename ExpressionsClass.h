#pragma once

#include "AllInclude.h"

class Expressions {
public:
    void IOExpr();
private:
    std::map <std::string, int> priority = { {"+", 1 },
                                             {"-", 1 },
                                             {"*", 2 },
                                             {"/", 2 },
                                             {"^", 3 },
                                             {"(", 0}
                                           };
    std::vector<std::string> AllOperation = { "+","-","*","/","^", "(", ")"};
<<<<<<< HEAD
    std::vector<std::string> AllNumbers = { "1","2","3","4","5","6","7","8","9","0" };
=======

>>>>>>> 4b86d48d7366c65aadb0f6eea5655b9ddfd1e98f
    std::stack <double> numbers;
    std::stack <std::string> operations;
    

   // std::string expression;

    double power(double a, double b);
    double StringToDouble(std::string s);
    std::string charToString(char c);

    double execution(std::string, double, double);
    std::vector<std::string> createTokens(std::string);
    double computation();

    double account(std::string);
<<<<<<< HEAD
};
=======
};

double Expressions::account(std::string expression)
{
    double tmp;
    std::vector<std::string> tokens = createTokens(expression);
    for (size_t i = 0; i < tokens.size(); i++)
    {
        //if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "^" || tokens[i] == "(" || tokens[i] == ")") {
        
        if (isElementInVector(AllOperation,tokens[i])){
            if (operations.empty()) {
                operations.push(tokens[i]);
            }
            else {
                if (tokens[i] == ")") {
                    while (operations.top() != "(") {
                        double tmp = computation();
                        numbers.push(tmp);
                    }
                    operations.pop();
                }
                else {
                    if (priority[operations.top()] < priority[tokens[i]]) {
                        operations.push(tokens[i]);
                    }
                    else {
                        while (priority[tokens[i]] <= priority[operations.top()]) {
                            tmp = computation();
                            numbers.push(tmp);
                        }
                        operations.push(tokens[i]);
                    }
                } 
            }
        }
        else {
            numbers.push(StringToDouble(tokens[i]));
        }
    }
    
    while (!operations.empty()) {
        tmp = computation();
        numbers.push(tmp);
    }



    return numbers.top();
}

std::vector<std::string> Expressions::createTokens(std::string s)
{
    std::vector<std::string> result;
    std::string tmp = "";

    for (size_t i = 0; i < s.size(); i++)
    {
        if (!isElementInVector(AllOperation, charToString(s[i]))) {
            tmp += s[i];
        }
        else {
            if (tmp != "") {
                result.push_back(tmp);
            }
            result.push_back(charToString(s[i]));
            tmp = "";
        }
    }
    result.push_back(tmp);

    return result;
}

double Expressions::StringToDouble(std::string s)
{
    double result;
    std::stringstream str;

    str << s;
    str >> result;
    return result;
}

std::string Expressions::charToString(char c)
{
    std::string result;
    std::stringstream str;

    str << c;
    str >> result;
    return result;
}

double Expressions::execution(std::string s, double a, double b)
{
    if (s == "+") return a + b;
    else if (s == "-") return a - b;
    else if (s == "*") return a * b;
    else if (s == "/") return a / b;
    else if (s == "^") return power(a, b);
}

double Expressions::power(double b, double a)
{
    double result  = 1;
    for (size_t i = 0; i < (b / 1); i++)
    {
        result *= a;
    }

    return result;
}

template <typename T>
T returnLastElementFromStack(std::stack<T> &stack) 
{
    T a = stack.top();
    stack.pop();
    return a;
}

double Expressions::computation()
{
    double tmpA = returnLastElementFromStack(numbers);
    double tmpB = returnLastElementFromStack(numbers);
    double tmp = execution(operations.top(), tmpA, tmpB);
    operations.pop();
    return tmp;
}

void Expressions::IOExpr() 
{
    std::string s;
    std::cout << "Enter th string: ";
    std::cin >> s;

    double result = account(s);

    std::cout << s << " = " << result << "\n\n";
}
>>>>>>> 4b86d48d7366c65aadb0f6eea5655b9ddfd1e98f
