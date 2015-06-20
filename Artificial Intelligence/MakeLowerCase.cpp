#include "MakeLowerCase.h"
#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

string makeLowerCase(const string& input)
{
	string output;

	transform(input.begin(), input.end(), back_inserter(output), ::tolower);
	return output;
}
