#include <iostream>
#include"Common.hpp"

using namespace std;
using namespace Utility;
int main(int argc, char const *argv[])
{
	// sort

	cout<<"\nSort characters\n\n";
	int i = 0;
	int size;
	cin>>size;
	char input[size];
	while(i< size){
		cin>>input[i++];
	}
	
	Common<char> c(input, size);
	cout<<"Original array: ";c.pArray(); // prints the array

	cout<<"Selction Sort: \n"; 	c.SelectionSort();
	cout<<"Insertion Sort: \n";	c.InsertionSort();
	cout<<"Merge Sort: \n";		c.MergeSort();
	cout<<"Quick Sort: \n";		c.QuickSort();
	cout<<"Counting Sort: \n";	c.CountingSort();
	// cout<<"Radix Sort: \n";		c.RadixSort();
	cout<<"Heap Sort: \n";		c.HeapSort();

	cout<<"\nSort integers\n\n";
	int numbers[] = {2,45,6,12,0};
	size = sizeof(numbers)/sizeof(numbers[0]);
	Common<int> c2(numbers, size);
	cout<<"Original array: ";c2.pArray(); // prints the array
	cout<<"Selction Sort: \n"; 	c2.SelectionSort();
	cout<<"Insertion Sort: \n";	c2.InsertionSort();
	cout<<"Merge Sort: \n";		c2.MergeSort();
	cout<<"Quick Sort: \n";		c2.QuickSort();
	cout<<"Counting Sort: \n";	c2.CountingSort();
	// cout<<"Radix Sort: \n";		c2.RadixSort();
	cout<<"Heap Sort: \n";		c2.HeapSort();

	cout<<"\nSort double \n\n";
	double collection[] = {2.4,4.5,0.6,12.90,0.004};
	size = sizeof(collection)/sizeof(collection[0]);
	Common<double> c3(collection, size);
	cout<<"Original array: ";c3.pArray(); // prints the array
	
	cout<<"Selction Sort: \n"; 	c3.SelectionSort();
	cout<<"Insertion Sort: \n";	c3.InsertionSort();
	cout<<"Merge Sort: \n";		c3.MergeSort();
	cout<<"Quick Sort: \n";		c3.QuickSort();
	cout<<"Counting Sort: \n";	c3.CountingSort();
	// cout<<"Radix Sort: \n";		c3.RadixSort();
	cout<<"Heap Sort: \n";		c3.HeapSort();
	
	return 0;
}