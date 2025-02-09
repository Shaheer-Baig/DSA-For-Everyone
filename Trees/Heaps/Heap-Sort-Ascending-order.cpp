#include<iostream>
using namespace std;


//Array ko max heap may convert karo
//Max Heap to sorted array

void Heapify(int arr[], int index, int n)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left<n && arr[left]>arr[largest]) {
		largest = left;
	}

	if (right<n && arr[right]>arr[largest])
		largest = right;
	if (largest != index)
	{
		swap(arr[largest], arr[index]);
		Heapify(arr,largest,n);
	}

}


void printHeap(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void BuildMaxHeep(int arr[], int n)
{
	//step down parent compared with children
	for (int i = n / 2 - 1; i >= 0; i--)
		//n-2-1 say start islay kiya q k baki sub k koy children nhi hy
	{
		Heapify(arr, i, n);
	}
}
void sortArray(int arr[], int n)
{
	for (int i = n-1; i > 0; i--)
	{
		swap(arr[i], arr[0]);
		Heapify(arr, 0, i);
	}
}


int main() {
	int arr[] = { 10,3,8,9,5,13,18,14,11,70 };
	BuildMaxHeep(arr, 10);
	sortArray(arr, 10);
	printHeap(arr, 10);
}
