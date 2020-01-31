# sortlib
sortlib is a c++ header provides implementation of sorting algorithms. sorting algorithms are implemented with class teamplates.

Usage:

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
