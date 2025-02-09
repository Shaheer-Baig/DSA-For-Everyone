#include <iostream>
using namespace std;

int main() {
    char array[10];  // Fixed-size array of 10 elements
    int size = 6;    // Initially, the array has 6 elements

    // Initialize the array with 6 elements
    array[0] = 'A';
    array[1] = 'B';
    array[2] = 'C';
    array[3] = 'D';
    array[4] = 'E';
    array[5] = 'F';

    // Display the initial array
    cout << "Initial array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Index to remove the element from (4th index - 5th position)
    int removeIndex = 4;

    // Check if the index to remove is valid
    if (removeIndex < size) {
        // Shift elements to the left from the removeIndex
        for (int i = removeIndex; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        
        // Decrease the size of the array
        size--;
    } else {
        cout << "Invalid index, cannot remove element." << endl;
    }

    // Display the array after removing the element at the 4th index
    cout << "Array after removing element at index " << removeIndex << ": ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
