# Hash Table (Hash Map)

A hash table (hash map) is a data structure that stores key-value pairs and allows fast retrieval of values using keys. It uses a hash function to map keys to specific indices in an array, ensuring efficient search, insertion, and deletion.

## How Does a Hash Table Work?
1. **Key Processing** → The input key is converted into an integer using a hash function.
2. **Index Calculation** → The integer is mapped to an index in a fixed-size array.
3. **Storage & Retrieval** → Data is stored at this computed index and retrieved in O(1) time on average.

## Why Use a Hash Table?
- **Fast Lookup** → Average O(1) time complexity for search, insert, and delete.
- **Efficient Memory Use** → Uses less space than direct key indexing.
- **Flexibility** → Supports different types of keys (strings, integers, etc.).
- **Widely Used** → Found in databases, caching, and language implementations.

## Where Are Hash Tables Used?
- **Compilers & Interpreters** → Store variable names and look them up quickly.
- **Databases** → Used in indexing and caching for fast lookups.
- **Cryptography** → Hash tables assist in storing hashed passwords securely.
- **Networking** → Used in routing tables, MAC address lookups, etc.
- **AI & Machine Learning** → Optimizes data retrieval in large datasets.

## Types of Hash Tables
### Open Addressing Hash Table
- Handles collisions by probing (linear, quadratic, or double hashing).
- Stores elements directly in the array.
- Example: Python’s `dict` uses open addressing.

### Separate Chaining Hash Table
- Uses linked lists (or balanced trees) at each index to handle collisions.
- Example: Java’s `HashMap` uses separate chaining.

### Perfect Hashing
- Designed to work without collisions, often using two-level hashing.
- Used in static key sets (e.g., compiler keyword lookups).

## Problems & Challenges in Hash Tables
### 1. Hash Collisions
- When two keys hash to the same index, we get a collision.
- **Solution:** Use separate chaining or open addressing.

### 2. Poor Hash Function
- A bad hash function can cause clustering, making searches slow.
- **Solution:** Use a well-distributed hash function like MurmurHash, SHA-256, or Jenkins Hash.

### 3. Space Overhead
- Requires extra memory for efficient operations.
- **Solution:** Optimize load factor (number of elements / table size).

### 4. Resizing Overhead
- Hash tables need resizing when they become too full, which is costly.
- **Solution:** Resize when load factor > 0.7.

### 5. Poor Performance in Worst Case
- If all keys hash to the same index, the worst-case search time is O(n).
- **Solution:** Use balanced tree chaining (e.g., Java’s HashMap turns to Red-Black Trees if collisions are high).

## Time Complexity Analysis

| Operation | Best Case (No Collisions) | Worst Case (Many Collisions) |
|-----------|--------------------------|------------------------------|
| Search    | O(1)                      | O(n)                         |
| Insert    | O(1)                      | O(n)                         |
| Delete    | O(1)                      | O(n)                         |

On average, hash tables offer O(1) time complexity, but collisions can degrade performance.


