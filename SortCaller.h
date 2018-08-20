
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>

#include "MergeSort.h"

using namespace std;

class SortCaller {

	vector<unsigned long int> inputVector;

public:

	SortCaller();

	SortCaller(vector<unsigned long int> vec);

	void CallSortOnVector();
};