#include <iostream>
using namespace std;

int getFirstElement(int arr[], int n) {
    return arr[0]; 
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "First Element: " << getFirstElement(arr, n) << endl;
    return 0;
}

