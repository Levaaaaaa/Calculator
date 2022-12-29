#pragma once


#include "Allinclude.h"

class HardMath
{
public:
	double derivative(std::function<double(double)> fun, double point);

	int checkInput(std::string, std::vector<int>);

	void SelectOperation();

	double sin(double a);
	double cos(double a);
	double tg(double a);
	double ctg(double a);

	double ln(double);
	double log(int ground, int number);
	double expon(double x);

	double arcsin(double b);
	double arccos(double b);
	double arctg(double b);
	double arcctg(double b);

	void HardMathUI();
	void SelectTrigonOperation();
	double request();
};

