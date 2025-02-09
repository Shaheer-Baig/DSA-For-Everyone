## Separate Chaining

Separate Chaining is a method for handling collisions in a hash table. When two or more keys hash to the same index (bucket), they are stored in a linked list (or another data structure) at that index. Each bucket in the hash table acts as a container for multiple key-value pairs.

### How Separate Chaining Works:

#### Hash Function:
- A hash function computes the index for a given key.
- Example: `hash(key) = key % table_size`.

#### Insertion:
1. Compute the hash of the key to determine the bucket index.
2. If the bucket is empty, store the key-value pair there.
3. If the bucket is not empty (collision occurs), append the key-value pair to the linked list at that bucket.

#### Lookup:
1. Compute the hash of the key to determine the bucket index.
2. Search the linked list at that bucket for the key.
3. If found, return the associated value; otherwise, return "not found."

#### Deletion:
1. Compute the hash of the key to determine the bucket index.
2. Search the linked list at that bucket for the key.
3. If found, remove the key-value pair from the linked list.

### Example:

Consider a hash table with 5 buckets and the following keys:

**Keys:** `10, 20, 30, 40, 50`

**Hash Function:** `hash(key) = key % 5`

#### Step-by-Step Insertion:

- **Insert 10:**  
  - Hash: `10 % 5 = 0`  
  - Bucket 0: `[10]`
- **Insert 20:**  
  - Hash: `20 % 5 = 0`  
  - Bucket 0: `[10 → 20]`
- **Insert 30:**  
  - Hash: `30 % 5 = 0`  
  - Bucket 0: `[10 → 20 → 30]`
- **Insert 40:**  
  - Hash: `40 % 5 = 0`  
  - Bucket 0: `[10 → 20 → 30 → 40]`
- **Insert 50:**  
  - Hash: `50 % 5 = 0`  
  - Bucket 0: `[10 → 20 → 30 → 40 → 50]`

#### Final Hash Table:
```
Bucket 0: [10 → 20 → 30 → 40 → 50]
Bucket 1: []
Bucket 2: []
Bucket 3: []
Bucket 4: []
```

### Advantages of Separate Chaining:

#### Simplicity:
- Easy to implement using linked lists or other dynamic data structures.

#### Handles High Load Factor:
- Can accommodate more elements than the table size by growing the linked lists.

#### No Clustering:
- Unlike open addressing, separate chaining does not suffer from clustering issues.

#### Dynamic:
- Linked lists can grow or shrink dynamically as needed.

### Disadvantages of Separate Chaining:

#### Memory Overhead:
- Each node in the linked list requires additional memory for pointers.

#### Cache Inefficiency:
- Linked lists are not cache-friendly, as nodes may be scattered in memory.

#### Worst-Case Performance:
- If all keys hash to the same bucket, the linked list becomes a linear list, degrading performance to `O(n)`.

### Time Complexity:

| Operation | Average Case | Worst Case |
|-----------|-------------|------------|
| Insertion | `O(1)`      | `O(n)`     |
| Lookup    | `O(1)`      | `O(n)`     |
| Deletion  | `O(1)`      | `O(n)`     |

- **Average Case:** Assumes a good hash function and a low load factor.
- **Worst Case:** Occurs when all keys hash to the same bucket, resulting in a linked list of size `n`.

### Optimizations for Separate Chaining:

#### Balanced BSTs:
- Use a balanced binary search tree (e.g., AVL tree, Red-Black tree) instead of a linked list to reduce the worst-case lookup time to `O(log n)`.

#### Dynamic Resizing:
- Resize the hash table and rehash all keys when the load factor exceeds a threshold (e.g., `0.7`).

#### Better Hash Functions:
- Use a hash function that distributes keys more uniformly across buckets.

### Applications of Separate Chaining:

#### Databases:
- Used in indexing and hash-based joins.

#### Programming Languages:
- Implementations of hash-based data structures like Python's `dict` or Java's `HashMap`.

#### Caching:
- Used in systems like Memcached or Redis.

#### Symbol Tables:
- Used in compilers to store variables and functions.
