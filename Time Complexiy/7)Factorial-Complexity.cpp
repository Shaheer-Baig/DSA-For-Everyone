#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r) cout << str << endl;
    else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]); // Backtrack
        }
    }
}

int main() {
    string str = "ABC";
    cout << "Permutations of " << str << ":\n";
    permute(str, 0, str.length() - 1);
    return 0;
}
