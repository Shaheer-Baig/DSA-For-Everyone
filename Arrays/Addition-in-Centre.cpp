#include <iostream>
using namespace std;

int main() {
    char array[10];  // Fixed-size array of 10 elements
    int size = 5;    // Initially, the array has 5 elements

    // Initialize the array with 5 elements
    array[0] = 'A';
    array[1] = 'B';
    array[2] = 'C';
    array[3] = 'D';
    array[4] = 'E';

    // Display the initial array
    cout << "Initial array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // New element to be added at the 3rd index (4th position)
    char newElement = 'X';
    int insertIndex = 3;  // Index where we want to insert the new element

    // Check if there is space in the array to add a new element
    if (size < 10) {
        // Shift elements to the right from the insertIndex
        for (int i = size; i > insertIndex; i--) {
            array[i] = array[i - 1];
        }

        // Insert the new element at the specified index
        array[insertIndex] = newElement;

        // Increase the size of the array
        size++;
    } else {
        cout << "Array is full, cannot add new element." << endl;
    }

    // Display the array after adding the new element at the 3rd index
    cout << "Array after adding new element at index " << insertIndex << ": ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
