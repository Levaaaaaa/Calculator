#include "HardMath.h"
#define _USE_MATH_DEFINES
#include <cmath>

double HardMath::derivative(std::function<double(double)> fun, double point)
{
    double h = 0.001;
    double result = (fun(point + h) - fun(point))/h;

    return result;
}

double testDerivativeFun(double d)
{
    return 3 * d * d * d + 2 * d * d + 5*d + 3;
}

double HardMath::sin(double d)
{
        return d - d * d * d / 6 + d * d * d * d * d / 120;
}

double HardMath::cos(double d)
{
    return 1 - d * d / 2 + d * d * d * d / 24;
}

double HardMath::tg(double d)
{
    return sin(d) / cos(d);
}

double HardMath::ctg(double d)
{
    return 1 / tg(d);
}

double HardMath::arcsin(double d)
{
    return d/sqrt(1-d*d)+(d*d*d)/(2*(1-d*d)*sqrt(1-d*d))*10;
}

double HardMath::expon(double d)
{
    return 1 + d + d * d / 2 + d * d * d / 6 + d * d * d * d / 24;
}

double HardMath::ln(double d)
{
    return round((d - 1) - (d - 1) * (d - 1) / 2 + (d - 1) * (d - 1) * (d - 1) / 3);
}

double HardMath::log(int ground, int value)
{
    return ln(value) / ln(ground);
}

void HardMath::HardMathUI()
{
    int mode;
    bool run = true;

    //std::vector<std::function<double(double)>> allOperation{ sin };
    std::vector<int> variableMode = { 0,1,2,3 };
    while (run) {
        run = false;
        std::string titleMode = "Select the mode:\n\t1 - Trigonometry\n";//\t2 - Inverse Triginometry\n\t3 - Exponenta\n\t0 - Back\n";

        mode = checkInput(titleMode, variableMode);

        try {
            switch (mode) {
            case 0: return;
            case 1:
                SelectTrigonOperation();
            }
        }
        catch (int i) {
            run = true;
        }
    }
}

void HardMath::SelectTrigonOperation()
{
    int operation;
    bool run = true;
    std::vector<int> variableOperation{ 0,1,2,3,4 };
    while (run) {
        std::string TrigonOperation = "Select the operation\n\t1 - Sin\n\t2 - Cos\n\t3 - Tg\n\t4 - Ctg\n\t0 - Back\n";
        operation = checkInput(TrigonOperation, variableOperation);
        double val;
        switch (operation) {
        case 0:
            throw 3;
            return;
        case 1:
            val = request();
            std::cout << "Sin " << val << " is " << sin(val) << "\n";
            break;
        case 2:
            val = request();
            std::cout << "Cos " << val << " is " << cos(val) << "\n";
            break;
        case 3:
            val = request();
            std::cout << "Tg " << val << " is " << tg(val) << "\n";
            break;
        case 4:
            val = request();
            std::cout << "Ctg " << val << " is " << ctg(val) << "\n";
            break;
        }
    }
}

double HardMath::request()
{
    double result;
    std::cout << "Enter the value ";
    std::cin >> result;
    return result;
}
int HardMath::checkInput(std::string title, std::vector<int> variableValues)
{
    int result;
    bool run = true;
    while (run) {
        run = false;
        std::cout << title;
        std::cin >> result;
        if (!isElementInVector(variableValues, result)) {
            run = true;
            std::cout << "\nUncorrect input\n";
        }
    }
    return result;
}