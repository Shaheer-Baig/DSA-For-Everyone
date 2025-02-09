# Open Addressing in Hash Tables

Open Addressing is a method for handling hash collisions where all elements are stored inside the hash table itself (i.e., no linked lists or external structures like in separate chaining). Instead of using a linked list at each index, open addressing finds an alternative empty slot within the array when a collision occurs.

## How Open Addressing Works
1. Compute the hash index using a hash function:
   ```
   index = hash(key) mod table_size
   ```
2. If the slot is occupied, find the next available slot using a probing technique.
3. Store the key-value pair in the first empty slot found.
4. During search and deletion, the same probing sequence is followed.

## Probing Techniques in Open Addressing
There are three main types of probing used in open addressing:

### Linear Probing
- Finds the next available slot by moving sequentially.
- If a collision occurs, check `index + 1`, `index + 2`, ... until an empty slot is found.
- This method is simple but causes clustering, where too many elements group together.

#### Formula:
```
index = (hash(key) + i) mod table_size
```
(where `i = 0, 1, 2, 3, ...`)

#### Example:
Suppose we insert keys `5, 15, 25` into a hash table of size `10`, and the hash function is:
```
index = key mod 10
```
- `5` hashes to index `5` (empty, so insert).
- `15` hashes to index `5` (collision). Try index `6` (empty, insert).
- `25` hashes to index `5` (collision). Try index `6` (occupied), then index `7` (empty, insert).

#### Final Table:
| Index  | 0 | 1 | 2 | 3 | 4 | 5  | 6  | 7  | 8 | 9 |
|--------|---|---|---|---|---|----|----|----|---|---|
| Value  | - | - | - | - | - | 5  | 15 | 25 | - | - |

**Problem:** Primary Clustering - Long sequences of occupied slots slow down insertions & lookups.

### Quadratic Probing
- Finds the next slot using a quadratic function instead of a simple increment.
- Reduces clustering by skipping spaces non-linearly.

#### Formula:
```
index = (hash(key) + i^2) mod table_size
```
(where `i = 0, 1, 2, 3, ...`)

#### Example:
(Same keys as before: `5, 15, 25`)
- `5` hashes to index `5` (empty).
- `15` hashes to index `5` (collision). Try index `5 + 1² = 6` (empty).
- `25` hashes to index `5` (collision). Try index `5 + 1² = 6` (occupied). Try index `5 + 2² = 9` (empty).

#### Final Table:
| Index  | 0 | 1 | 2 | 3 | 4 | 5  | 6  | 7 | 8 | 9  |
|--------|---|---|---|---|---|----|----|---|---|----|
| Value  | - | - | - | - | - | 5  | 15 | - | - | 25 |

**Problem:** Secondary Clustering - Elements with the same hash follow the same probing sequence, leading to clustering.

### Double Hashing
- Uses a second hash function to calculate step size, making probing non-linear.
- This eliminates clustering and improves performance.

#### Formula:
```
index = (hash1(key) + i × hash2(key)) mod table_size
```
(where `i = 0, 1, 2, 3, ...` and `hash2(key) ≠ 0`)

#### Example:
Let:
```
hash1(key) = key mod 10
hash2(key) = 7 - (key mod 7)
```
Insert `5, 15, 25`:
- `5` hashes to index `5` (empty).
- `15` hashes to index `5` (collision). `hash2(15) = 7 - (15 mod 7) = 6`. Try index `(5 + 1×6) mod 10 = 1` (empty).
- `25` hashes to index `5` (collision). `hash2(25) = 7 - (25 mod 7) = 3`. Try index `(5 + 1×3) mod 10 = 8` (empty).

#### Final Table:
| Index  | 0 | 1  | 2 | 3 | 4 | 5  | 6 | 7 | 8  | 9 |
|--------|---|----|---|---|---|----|---|---|----|---|
| Value  | - | 15 | - | - | - | 5  | - | - | 25 | - |

**No Clustering Problem:** Best among the three methods but requires a good secondary hash function.

## Open Addressing: Time Complexity

| Operation  | Best Case (No Collision) | Worst Case (Clustering) |
|------------|-------------------------|-------------------------|
| **Search** | O(1)                    | O(n)                    |
| **Insert** | O(1)                    | O(n)                    |
| **Delete** | O(1)                    | O(n)                    |

**Linear Probing suffers the most in worst-case scenarios due to clustering.**

**Double Hashing offers the best performance.**

## Open Addressing vs Separate Chaining

| Feature                     | Open Addressing                  | Separate Chaining                |
|-----------------------------|----------------------------------|----------------------------------|
| **Memory Usage**            | Less (no extra space for links)  | More (extra pointers for linked lists) |
| **Insertion Speed**         | O(1) (on average)                | O(1) (on average)                |
| **Deletion Complexity**     | Tricky (special markers needed)  | Easier                           |
| **Performance when load increases** | Decreases significantly        | Handles load better              |
| **Cache Efficiency**        | Higher (all elements in one array) | Lower (pointers spread across memory) |

---


