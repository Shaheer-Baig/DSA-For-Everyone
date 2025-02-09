# Binary Search Tree (BST)

## What is a Binary Search Tree (BST)?
A Binary Search Tree (BST) is a specialized form of a binary tree where each node satisfies the binary search property:

- **Left Subtree**: Contains nodes with values **less** than the node's value.
- **Right Subtree**: Contains nodes with values **greater** than the node's value.
- Both the left and right subtrees must also be **binary search trees**.

## Components of a BST
- **Nodes**: Represent data (each node has a value).
- **Edges**: Connections between nodes (parent-child relationship).
- **Root**: The starting node of the BST.
- **Leaves**: Nodes with no children.
- **Left Subtree**: Nodes with values smaller than their parent node.
- **Right Subtree**: Nodes with values larger than their parent node.

## Where are BSTs Used?
### **Efficient Searching**:
- Searching for values using **O(log n)** time in balanced BSTs.

### **Dynamic Sets**:
- Keeping dynamic sets sorted, like in **sets** and **multisets** in C++ STL.

### **Databases**:
- Indexing data for **fast retrieval**.

### **Sorting**:
- **Inorder traversal** of a BST provides **sorted data**.

---

## Tree Traversal Methods in BST
Traversal in a BST follows **binary tree traversal techniques** but benefits from the BST property for **sorted data in inorder traversal**.

### 1. **Inorder Traversal**
- **Order**: Left → Root → Right
- Returns elements in **ascending order** for a BST.

#### Example:
#### **Tree Structure:**
```
    10
   /  \
  5    15
```
**Inorder Traversal**: `5 → 10 → 15`

---

### 2. **Preorder Traversal**
- **Order**: Root → Left → Right
- Useful for **copying the tree** or generating **prefix expressions**.

#### Example:
#### **Tree Structure:**
```
    10
   /  \
  5    15
```
**Preorder Traversal**: `10 → 5 → 15`

---

### 3. **Postorder Traversal**
- **Order**: Left → Right → Root
- Often used for **deleting nodes** or evaluating **postfix expressions**.

#### Example:
#### **Tree Structure:**
```
    10
   /  \
  5    15
```
**Postorder Traversal**: `5 → 15 → 10`

---

## Operations in a BST

### **1. Insertion**
To insert a value:
- Start from the **root**.
- Compare the value with the current node:
  - If **smaller**, move to the **left subtree**.
  - If **larger**, move to the **right subtree**.
- Insert the value at the correct **NULL position**.

**Time Complexity:**
- **Best Case (Balanced BST)**: `O(log n)`
- **Worst Case (Skewed BST)**: `O(n)`

---

### **2. Deletion**
To delete a node:
1. **Locate the node** to delete.
2. Handle one of the **three cases**:
   - **No children (leaf)**: Simply remove the node.
   - **One child**: Replace the node with its child.
   - **Two children**:
     - Replace the node with the **inorder predecessor** (max of the left subtree) or **inorder successor** (min of the right subtree).
     - Delete the **predecessor/successor node**.
   - Maintain the **BST property** during deletion.

**Time Complexity:**
- **Best Case (Balanced BST)**: `O(log n)`
- **Worst Case (Skewed BST)**: `O(n)`

---

### **3. Search**
To search for a value:
- Start from the **root**.
- Compare the value with the **current node**.
- Traverse **left or right** based on the comparison.
- Return **true** if the value is found, else return **false** if you reach `NULL`.

**Time Complexity:**
- **Best Case (Balanced BST)**: `O(log n)`
- **Worst Case (Skewed BST)**: `O(n)`

---

### **4. Traversal**
Traversing all nodes using **inorder, preorder, or postorder** involves visiting **each node exactly once**.

**Time Complexity**: `O(n)`

---

## **Time Complexities of BST Operations**

| Operation   | Balanced BST `O(...)` | Skewed BST `O(...)` | Explanation |
|------------|----------------------|--------------------|-------------|
| **Insertion**  | `log n` | `n` | Comparison-based placement. |
| **Deletion**   | `log n` | `n` | Finding and restructuring can be costly. |
| **Search**     | `log n` | `n` | Traversal depends on the height of the tree. |
| **Traversal**  | `n` | `n` | Visits every node exactly once. |

---

## **Advantages of a BST**
 **Fast searching, insertion, and deletion** in balanced trees.
 **Dynamic data structure**: Easy to **add or remove elements**.
 **Inorder traversal gives sorted data**.

---

## **Disadvantages of a BST**
 **Performance degrades to `O(n)`** in **skewed trees**.
 **Requires rebalancing** (in **AVL** or **Red-Black Trees**) to maintain efficiency.

---

This detailed breakdown should be helpful for your notes! Let me know if you'd like **examples or diagrams** for **better visualization**. 🚀

