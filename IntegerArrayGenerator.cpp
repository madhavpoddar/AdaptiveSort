
#include "stdafx.h"

#include "IntegerArrayGenerator.h"
#include <algorithm>

using namespace std;
using namespace chrono;

int main()
{
	unsigned long int j, size, lowerLimit = 0, upperLimit, sort_percentage, number_of_tries = 1;

	time_t t;
	/* Intializes random number generator */
	srand((unsigned)time(&t));


	for (size = 10; size<1001; size *= 10)
	{
		for (upperLimit = 30; upperLimit < RAND_MAX; upperLimit *= 10)
		{
			for (sort_percentage = 0; sort_percentage <= 100; sort_percentage += 10)
			{
				vector<unsigned long int> inputVector;
				cout << endl;
				cout << "Size: " << size << " Upper Limit: " << upperLimit << " Lower Limit: " << lowerLimit << endl;

				for (j = 0; j <= size - 1; j++) {
					unsigned long int temp = lowerLimit + rand() % (upperLimit - lowerLimit + 1);
					inputVector.push_back(temp);
				}

				if (sort_percentage == 100)
				{
					cout << "Pre-sort percentage : Entire Array except the last element" << endl;
					sort(inputVector.begin(), inputVector.end() - 1);
				}
				else if (sort_percentage)
				{
					cout << "Pre-sort percentage : " << sort_percentage << endl;
					sort(inputVector.begin(), inputVector.begin() + size * sort_percentage / 100);
				}

				cout << "Calling sort on the vector";
				SortCaller objSortCaller = SortCaller(inputVector);
				objSortCaller.CallSortOnVector();
			}
		}
	}


	getchar();


	return 0;
}
