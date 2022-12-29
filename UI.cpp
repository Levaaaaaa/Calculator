#include "UI.h"
#include "ExpressionsClass.h"

void UI() {

	bool run = true;
	while (run) {
		int typeOfOperation = SelectTypeOfOperation();

		switch (typeOfOperation) {
		case 0:
		{
			run = false;
			continue;
		}
		case 1:
		{
			SelectUnOperation();
			break;
		}
		case 2:
		{
			SelectBinOperation();
			break;
		case 3:
			Expressions expr;
			expr.IOExpr();
		}
		case 3:
		{
			Expressions expr;
			expr.IOExpr();
			break;
		}
		case 4:
		{
			HardMath math;
			math.HardMathUI();
		}
		}
	}
}

int SelectTypeOfOperation() 
{
<<<<<<< HEAD
	std::vector<int> variableTypes = { 0,1,2, 3,4 };
=======
	std::vector<int> variableTypes = { 0,1,2, 3 };
>>>>>>> 4b86d48d7366c65aadb0f6eea5655b9ddfd1e98f

	int typeOfOperation = -1;

	do {
<<<<<<< HEAD
		std::cout << "Select the type:\n\t1. Unary\n\t2. Binary\n\t3. Strings\n\t4. Mathematic\n\t0. Exit\n";
=======
		std::cout << "Select the type:\n\t1. Unary\n\t2. Binary\n\t3. Strings\n\t0. Exit\n";
>>>>>>> 4b86d48d7366c65aadb0f6eea5655b9ddfd1e98f
		std::cin >> typeOfOperation;
	} while (!isElementInVector(variableTypes, typeOfOperation));

	return typeOfOperation;
}

int SelectSpecies()
{
	std::vector<int> variableTypes = { 0,1,2 };

	int species;

	do {
		std::cout << "Select the species of operation:\n\t1. Arithmetic\n\t2. Logic\n\t0. Back\n";
		std::cin >> species;
	} while (!isElementInVector(variableTypes, species));

	return species;
}

void SelectUnOperation()
{
	int operation;

	bool run = true;

	while (run) {
		int species = SelectSpecies();

		switch (species) {
		case 0:
			run = false;
			continue;
		case 1:
			requestUnArithmOp();	// запросить бинарные арифметические операции
			break;
		case 2:
			requestUnLogOp();
			break;
		}
	}
}

void SelectBinOperation()	//вызывать если операция бинарная (typeOfOperation = 2)
{
	int operation;

	bool run = true;

	while (run) {
		int species = SelectSpecies();

		switch (species) {
		case 0:
			run = false;
			continue;
		case 1:
			requestBinArithmOp();	// запросить бинарные арифметические операции
			break;
		case 2:
			requestBinLogOp();
			break;
		}
	}
}