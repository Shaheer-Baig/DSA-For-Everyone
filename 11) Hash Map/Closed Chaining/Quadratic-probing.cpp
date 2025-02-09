#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    int size;
    vector<int> table;
    vector<bool> occupied; // To track occupied slots

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s), table(s, -1), occupied(s, false) {}

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (occupied[(index + i * i) % size]) {
            i++;
            if (i == size) {
                cout << "Hash Table is full!" << endl;
                return;
            }
        }

        index = (index + i * i) % size;
        table[index] = key;
        occupied[index] = true;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (occupied[(index + i * i) % size]) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == key)
                return true;
            i++;
            if (i == size)
                return false;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (occupied[(index + i * i) % size]) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == key) {
                table[newIndex] = -1;
                occupied[newIndex] = false;
                return;
            }
            i++;
            if (i == size)
                return;
        }
        cout << "Key not found!" << endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (occupied[i])
                cout << i << " -> " << table[i] << endl;
            else
                cout << i << " -> Empty" << endl;
        }
    }
};

int main() {
    int size = 10;
    HashTable ht(size);

    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    
    cout << "Hash Table after insertion:" << endl;
    ht.display();

    cout << "\nSearching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    
    ht.remove(15);
    cout << "\nHash Table after deleting 15:" << endl;
    ht.display();

    return 0;
}

