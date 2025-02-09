#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    int tableSize; // Size of the hash table
    vector<list<pair<int, int>>> table; // Vector of linked lists to store key-value pairs

    // Hash function to compute the index for a given key
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Constructor to initialize the hash table
    HashTable(int size) : tableSize(size), table(size) {}

    // Insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashFunction(key); // Compute the index
        table[index].push_back({ key, value }); // Add the key-value pair to the linked list at the index
    }

    // Search for a key in the hash table and return its value
    int search(int key) {
        int index = hashFunction(key); // Compute the index
        for (auto& pair : table[index]) { // Traverse the linked list at the index
            if (pair.first == key) {
                return pair.second; // Return the value if the key is found
            }
        }
        return -1; // Return -1 if the key is not found
    }

    // Remove a key-value pair from the hash table
    void remove(int key) {
        int index = hashFunction(key); // Compute the index
        table[index].remove_if([key](const pair<int, int>& pair) {
            return pair.first == key; // Remove the pair if the key matches
            });
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Bucket " << i << ": ";
            for (auto& pair : table[i]) {
                cout << "(" << pair.first << ", " << pair.second << ") -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    //Create a hash table with 5 buckets
    HashTable ht(5);

    // Insert key-value pairs
    ht.insert(10, 100);
    ht.insert(20, 200);
    ht.insert(30, 300);
    ht.insert(40, 400);
    ht.insert(50, 500);
    ht.insert(15, 150); // Collision with key 10 (both hash to index 0)

    // Display the hash table
    cout << "Hash Table after insertions:" << endl;
    ht.display();

    // Search for a key
    int key = 20;
    int value = ht.search(key);
    if (value != -1) {
        cout << "Value for key " << key << ": " << value << endl;
    }
    else {
        cout << "Key " << key << " not found!" << endl;
    }

    // Remove a key
    ht.remove(20);
    cout << "Hash Table after removing key 20:" << endl;
    ht.display();

    // Search for the removed key
    value = ht.search(key);
    if (value != -1) {
        cout << "Value for key " << key << ": " << value << endl;
    }
    else {
        cout << "Key " << key << " not found!" << endl;
    }

    return 0;
}
