#pragma once

#define M_PI 3.14159265358979323846
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <stack>
#include <sstream>

<<<<<<< HEAD
#include "HardMath.h"

=======
>>>>>>> 4b86d48d7366c65aadb0f6eea5655b9ddfd1e98f

template <typename T>
bool isElementInVector(std::vector<T> v, T e)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (e == v[i]) {
			return true;
		}
	}

	return false;
}