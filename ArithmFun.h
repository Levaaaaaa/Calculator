#pragma once

#include "AllInclude.h"

void Add();

void multiply();

void factorial();

bool checkNumberInString(std::istream&);

double checkInputArithmFun(std::string);

std::vector<std::function<void()>> VectorOfBinArithmFun();

std::vector<std::function<void()>> VectorOfUnArithmFun();

void requestBinArithmOp();

void requestUnArithmOp();
