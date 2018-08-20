
#include "stdafx.h"

#include "IntegerArrayGenerator.h"

using namespace std;
using namespace chrono;

int main()
{
	unsigned long int i, j, sizeOfArray = 50000, lowerLimitOfArray = 0, upperLimitOfArray = 100000, numOfArrays = 1;
	unsigned long int size, lowerLimit, upperLimit;
	high_resolution_clock::time_point t1, t2;

	time_t t;
	/* Intializes random number generator */
	srand((unsigned)time(&t));
	
	for (i = 0; i < numOfArrays - 1; i++)
	{
		vector<unsigned long int> inputVector;
		size = rand() % (sizeOfArray + 1);
		lowerLimit = lowerLimitOfArray;
		upperLimit = rand() %  (upperLimitOfArray +1);
		cout << "Generating Array " << i + 1;
		cout << "Size: " << size << " Upper Limit: " << upperLimit << " Lower Limit: " << lowerLimit;
		for (j = 0; j < size-1; j++) {
			unsigned long int temp = lowerLimit + rand() % (upperLimit - lowerLimit + 1);
			inputVector.push_back(temp);
		}
		cout << "Writing to a file";
		std::ofstream output_file(to_string(i + 1) + ".txt");
		std::ostream_iterator<std::string> output_iterator(output_file, "\n");
		std::copy(inputVector.begin(), inputVector.end(), output_iterator);
		cout << "Calling sort on the vector";
		SortCaller objSortCaller = SortCaller(inputVector);
		objSortCaller.CallSortOnVector();
	}


	cin.get();


	return 0;
}
