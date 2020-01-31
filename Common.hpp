#ifndef UTILITY_H
#define UTILITY_H 

#include <iostream>
#include<vector>

using namespace std;


namespace Utility{

	template <typename T>
	class Common
	{

	private:

		T *ptr;
		int size;
		string welcome = "Hello, World";

	public:
		Common(T InArray[], int size);
		void pArray();
		void print();
		void BubbleSort();
		void SelectionSort();
		void InsertionSort();
		void MergeSort();
		void ProcessMergeSort(T *array, int left, int right);
		void Merge(T *array, int left, int mid, int right);
		void QuickSort();
		void ProcessQuickSort(T *ptr, int left, int right);
		int PartitionQuickSort(T *ptr, int left, int right);
		void CountingSort();
		void RadixSort();
		void RadixByCountSort(int exponent);
		void HeapSort();
		void ProcessBuildHeap(int middlePosition);
		void ProcessMaxHepify(T *ptr, int position, int size);

		void pArray(vector<T> a){
			for(int i=0; i< a.size(); i++){
				cout<<a[i]<<" ";
			}
			cout<<'\n';
		};

	};

	// Class Constructor
	template<typename T>
	Common<T>::Common(T InArray[], int size){
		ptr = new T[size];
		this->size = size;
		for(int i=0; i< size; i++){
			ptr[i] = InArray[i];
		}
	}

	// Common class methods
	// #1
	template<typename T>
	void Common<T>::print(){
		cout<<welcome<<endl;
	}

	//#2
	template<typename T>
	void Common<T>::pArray(){
		for(int i=0; i< size; i++){
			cout<<ptr[i]<<" ";
		}
		cout<<'\n';
	}	

	//#3 Bubble Sort
	template<typename T>
	void Common<T>::BubbleSort(){

		// number of times to loop
		for(int i=0; i< size-1; i++){

			// number of times to compare for each iteration
			for(int j=0; j< size-1-i; j++){
				if(ptr[j] > ptr[j+1]){
					int temp = ptr[j];
					ptr[j] = ptr[j+1];
					ptr[j+1] = temp;
				}
			}
		}
	}

	//#4 Selection Sort
	template<typename T>
	void Common<T>::SelectionSort(){

		for(int i=0; i< size-1; i++){
			int minimum = i;
			for(int j=i+1; j< size; j++){
				if(ptr[j] < ptr[minimum] ){
					// cout<<ptr[i]<<" - "<<ptr[j]<<endl;
					minimum = j;
				}
			}
			T a = ptr[i];
			ptr[i] = ptr[minimum];
			ptr[minimum] = a;
		}
		pArray();
	}

	//#5 InsertionSort
	template<typename T>
	void Common<T>::InsertionSort(){

		for(int i=0; i< size; i++){
			T temp = ptr[i];
			int j = i;
			while(j>0 && temp<ptr[j-1]){
				ptr[j] = ptr[j-1];
				j=j-1;
			}
			ptr[j] = temp;
		}
		pArray();
	}

	//#6 MergeSort
	template<typename T>
	void Common<T>::MergeSort(){
		ProcessMergeSort(ptr, 0, this->size-1);
		pArray();
	}

	template<typename T>
	void Common<T>::ProcessMergeSort(T *ptr, 
		int l, int r){

		// cout<<"l: "<<l<<"r: "<<r<<endl;
		if(l<r){
			int mid = l+(r-l)/2;

			ProcessMergeSort(ptr, l, mid);
			ProcessMergeSort(ptr, mid+1, r);
			Merge(ptr, l, mid, r);
		}
	}

	template<typename T>
	void Common<T>::Merge(T *ptr, int l, 
		int m, int r){
		int i, j, k;
		int n1 = m-l+1;
		int n2 = r-m;

		T L[n1], R[n2];

		for(i=0; i< n1; i++){
			L[i]=ptr[l+i];
		}
		for(j=0; j< n2; j++){
			R[j]=ptr[m+1+j];
		}

		i=0; j=0; k=l;

		while(i< n1 && j< n2){
			if(L[i] <= R[j]){
				ptr[k] = L[i];
				i++;
			}
			else{
				ptr[k] = R[j];
				j++;
			}
			k++;
		}

		while(i< n1){
			ptr[k] = L[i];
			i++;k++;
		}

		while(j< n2){
			ptr[k] = R[j];
			j++;k++;
		}
	}
	

	//#7 QuickSort	
	template<typename T>
	void Common<T>::QuickSort(){
		ProcessQuickSort(ptr, 0, size-1);
		pArray(); 
	}	

	template<typename T>
	void Common<T>::ProcessQuickSort(T *ptr, int left, int right){
		if(left < right){
			int pi = PartitionQuickSort(ptr, left, right);
			ProcessQuickSort(ptr, left, pi-1);
			ProcessQuickSort(ptr, pi+1, right);
		}
	}


	template<typename T>
	int Common<T>::PartitionQuickSort(T *ptr, int left, int right){
		T pivot = ptr[right];
		int i = left-1;

		for(int j = left; j<= right-1; j++){
			if(ptr[j] < pivot){
				i+=1;
				T temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}
		}

		i+=1;
		T temp = ptr[right];
		ptr[right] = ptr[i];
		ptr[i] = temp;

		return (i);
	}

	template<typename T>
	void Common<T>::CountingSort(){
		vector<T> sortedA;
		vector<T> aux; // to keep freq. of elements from array

		T K = 0;

		for(int i=0; i< size; i++){
			if(ptr[i]> K){
				K = ptr[i];
			}
		}

		for(int i=0; i<=K; i++){
			aux.push_back(0);
		}

		for(int i=0; i<size; i++){
			aux[ptr[i]]++;
		}

		int j=0;
		for(int i=0; i<= K; i++){
		 	int tmp = aux[i];
		 	// cout<<i<<" "<<tmp<<endl;
		 	while(tmp--){
		 		sortedA.push_back(i); 
		 		// j++;
		 	}

		}
		pArray(sortedA);
	}

	template<typename T>
	void Common<T>::RadixSort(){
		int max = ptr[0];
		for(int i=1; i< size; i++){
			if(ptr[i] > max){
				max = ptr[i];
			}
		}

		for(int exp = 1; max/exp > 0; exp*=10){
			RadixByCountSort(exp);
		}
	}

	template<typename T>
	void Common<T>::RadixByCountSort(int exp){
		// T output[] = new T[this->size];
		// T count[10] = {0};

		// for(int i =0; i< this->size; i++){
		// 	count[(ptr[i]/exp)%10]++;
		// }

		// for(int i =1; i< 10; i++){
		// 	count[i] += 
		// }

	}

	template<typename T>
	void Common<T>::HeapSort(){
		int mid = this->size/2 ;
		int heap_size  =this->size;
		ProcessBuildHeap(mid);
		// pArray();
		for(int i=this->size-1; i>=1; i--){
			T temp = ptr[i];
			ptr[i] = ptr[0];
			ptr[0] = temp;
			heap_size = heap_size-1;
			ProcessMaxHepify(ptr, 0, heap_size);
		}
		pArray();
	}

	template<typename T>
	void Common<T>::ProcessBuildHeap(int mid){

		for(int i= mid; i>=0; i--){
			ProcessMaxHepify(this->ptr, i, this->size);
		}
	}

	template<typename T>
	void Common<T>::ProcessMaxHepify(T *ptr, int i, int size){
		int left = 2*i;
		int right = 2*i+1;
		int largest = i;
		if(left< size && ptr[left]> ptr[i]) largest = left;
		else largest = i;
		if(right< size && ptr[right]> ptr[left]) largest = right;
		if(largest != i){
			T temp = ptr[i];
			ptr[i] = ptr[largest];
			ptr[largest] = temp;
			ProcessMaxHepify(ptr, largest, size);
		}
	}
}

#endif
