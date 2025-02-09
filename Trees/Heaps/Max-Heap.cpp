#include<iostream>
using namespace std;


class MaxHeap
{
	int* arr;
	int size; //total elements in heap
	int total_size; //total size of array


public:
	MaxHeap(int n) {
		arr = new int[n];
		size = 0;
		total_size = n;
	}

	//insert into the heap
	void insert(int value)
	{
		//if heap size is available 
		if (size == total_size)
		{
			cout << "Heap Overflow" << endl;
			return;
		}

		arr[size] = value;//size bata raha hy kitnay elements hy and uskay hisab say hy last per add hoga data
		int index;
		index = size;
		size++;

		// Comapre it with its parent
		while(index>0 && arr[(index-1)/2]<arr[index])//agar parent chota hoga to
		{
			swap(arr[index], arr[(index - 1) / 2]);//swapping parent with child
			index = (index - 1) / 2;//index move howa parent per takay next bar comparing asan ho
		}

		cout << arr[index] << " is inserted into the heap\n";
	}


	void print()
	{
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
			cout << endl;
	 }
	}

	void Heapify(int index)
	{
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		
		//largest will store the index of element
		//which is greater between parent, left child and right child
		
		if (left<size && arr[left]>arr[largest]) {
			largest = left;
		}

		if (right<size && arr[right]>arr[largest])
		largest = right;

		if (largest != index)
		{
			swap(arr[index], arr[largest]);
			Heapify(largest);
		}
	}


	void Delete()
	{
		if (size == 0)
		{
			cout << "Heap Underflow\n";
			return;
		}
		cout << arr[0] << " deleted from the heap"<<endl;
		arr[0] = arr[size - 1];//replace the last node with first
		size--;

		if (size == 0)
			return;
		//correct position per lay jana after deletion
		Heapify(0);
		//child node say comparison agar child bara to replace
	}
};

int main()
{

	MaxHeap H1(10);
	H1.insert(4);
	H1.insert(6);
	H1.insert(8);
	H1.insert(10);
	H1.print();
	H1.insert(12);
	H1.insert(14);
	H1.insert(5);
	H1.insert(100);
	H1.print();
	H1.Delete();
	H1.print();
	
}
