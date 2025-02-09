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

    // Remove the element at the head (index 0)
    if (size > 0) {
        // Shift all elements to the left by one position
        for (int i = 0; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        // Reduce the size of the array
        size--;
    } else {
        cout << "Array is empty, cannot remove element." << endl;
    }

    // Display the array after removing the element at the head
    cout << "Array after removing element from head: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
