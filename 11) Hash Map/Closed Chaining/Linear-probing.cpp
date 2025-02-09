#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    int tableSize; // Size of the hash table
    vector<pair<int, int>> table; // Vector to store key-value pairs
    vector<bool> isOccupied; // Vector to track occupied slots

    // Hash function to compute the index for a given key
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Constructor to initialize the hash table
    HashTable(int size) : tableSize(size), table(size, { -1, -1 }), isOccupied(size, false) {}

    // Insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashFunction(key); // Compute the initial index
        int originalIndex = index;

        // Linear probing to find the next available slot
        while (isOccupied[index]) {
            if (table[index].first == key) { // If key already exists, update the value
                table[index].second = value;
                return;
            }
            index = (index + 1) % tableSize; // Move to the next slot
            if (index == originalIndex) { // If we loop back to the original index, the table is full
                cout << "Hash table is full! Cannot insert key " << key << endl;
                return;
            }
        }

        // Insert the key-value pair
        table[index] = { key, value };
        isOccupied[index] = true;
    }

    // Search for a key in the hash table and return its value
    int search(int key) {
        int index = hashFunction(key); // Compute the initial index
        int originalIndex = index;

        // Linear probing to find the key
        while (isOccupied[index]) {
            if (table[index].first == key) {
                return table[index].second; // Return the value if the key is found
            }
            index = (index + 1) % tableSize; // Move to the next slot
            if (index == originalIndex) { // If we loop back to the original index, the key is not found
                break;
            }
        }

        return -1; // Return -1 if the key is not found
    }

    // Remove a key-value pair from the hash table
    void remove(int key) {
        int index = hashFunction(key); // Compute the initial index
        int originalIndex = index;

        // Linear probing to find the key
        while (isOccupied[index]) {
            if (table[index].first == key) {
                table[index] = { -1, -1 }; // Mark the slot as empty
                isOccupied[index] = false;
                return;
            }
            index = (index + 1) % tableSize; // Move to the next slot
            if (index == originalIndex) { // If we loop back to the original index, the key is not found
                break;
            }
        }

        cout << "Key " << key << " not found for deletion!" << endl;
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (isOccupied[i]) {
                cout << "Bucket " << i << ": (" << table[i].first << ", " << table[i].second << ")" << endl;
            }
            else {
                cout << "Bucket " << i << ": Empty" << endl;
            }
        }
    }
};

int main() {
    // Create a hash table with 5 buckets
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
