#include <iostream>
using namespace std;

int main() {
    char array[10];  // Fixed-size array of 10 elements
    int size = 5;    // Initially, the array has 5 elements

    // Initialize the array with 5 elements, leaving the rest empty
    array[0] = 'A';
    array[1] = 'B';
    array[2] = 'C';
    array[3] = 'D';
    array[4] = 'E';

    // Display the initial array (5 elements filled)
    cout << "Initial array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // New element to be added at the head
    char newElement = 'Z';

    // Check if the array has space to add a new element
    if (size < 10) {
        // Shift all elements one position to the right
        for (int i = size; i > 0; i--) {
            array[i] = array[i - 1];
        }

        // Insert the new element at the head (index 0)
        array[0] = newElement;

        // Increase the size of the array
        size++;
    } else {
        cout << "Array is full, cannot add new element." << endl;
    }

    // Display the array after adding the new element at the head
    cout << "Array after adding new element at head: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
