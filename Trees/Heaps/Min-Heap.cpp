#include <iostream>
using namespace std;

class MinHeap {
    int* arr;
    int size; // total elements in heap
    int total_size; // total size of array

public:
    MinHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert into the heap
    void insert(int value) {
        if (size == total_size) {
            cout << "Heap Overflow" << endl;
            return;
        }

        arr[size] = value; // Add at the end
        int index = size;
        size++;

        // Compare with its parent and maintain MinHeap property
        while (index > 0 && arr[(index - 1) / 2] > arr[index]) { // Parent is greater
            swap(arr[index], arr[(index - 1) / 2]); // Swap with parent
            index = (index - 1) / 2; // Move to parent index
        }

        cout << arr[index] << " is inserted into the heap\n";
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Heapify(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Find the smallest among parent, left child, and right child
        if (left < size && arr[left] < arr[smallest]) {
            smallest = left;
        }

        if (right < size && arr[right] < arr[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            Heapify(smallest); // Recursively heapify
        }
    }

    void Delete() {
        if (size == 0) {
            cout << "Heap Underflow\n";
            return;
        }
        cout << arr[0] << " deleted from the heap" << endl;
        arr[0] = arr[size - 1]; // Replace the last node with the first
        size--;

        if (size == 0)
            return;

        // Correct position after deletion
        Heapify(0);
    }
};

int main() {
    MinHeap H1(10);
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

    return 0;
}
