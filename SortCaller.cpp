
#include "stdafx.h"

#include "SortCaller.h"

using namespace chrono;

SortCaller::SortCaller()
{

}

SortCaller::SortCaller(vector<unsigned long int> vec)
{
	inputVector = vec;
}

void SortCaller::CallSortOnVector()
{
	high_resolution_clock::time_point t1, t2;
	duration<double> time_span;
	cout << "Calling Merge Sort";
	vector<unsigned long int> temp = inputVector;
	MergeSort objMergeSort = MergeSort();

	t1 = high_resolution_clock::now();
	objMergeSort.Sort(temp, 0, temp.size() - 1);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2 - t1);
	/*std::ofstream output_file("sorted.txt");
	std::ostream_iterator<string> output_iterator(output_file, "\n");
	for (const auto &e : temp) output_file << e << "\n";*/
	cout << "Time taken in Merge  Sort : " << time_span.count() << " seconds." << std::endl;


}