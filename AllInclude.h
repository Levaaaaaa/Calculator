#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <stack>
#include <sstream>


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