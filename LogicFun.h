#pragma once

#include "AllInclude.h"

void ne();

void conjunction();

void disjunction();

bool checkInputLogFun(std::string);

std::vector<std::function<void()>> VectorOfBinLogFun();

std::vector<std::function<void()>> VectorOfUnLogFun();

void requestUnLogOp();

void requestBinLogOp();