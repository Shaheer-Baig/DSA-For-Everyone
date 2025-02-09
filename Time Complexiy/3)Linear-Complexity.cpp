#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int main() {
    int arr[] = {10, 25, 47, 8, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Element: " << findMax(arr, n) << endl;
    return 0;
}
