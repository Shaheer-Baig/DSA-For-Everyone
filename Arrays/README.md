### Array-Based List

An **array-based list** is a dynamic data structure that uses an array to store elements. The size of this array can either be fixed or dynamically resized as the number of elements grows. This structure is commonly referred to as a **dynamic array** in data structures, and a well-known example is the **ArrayList** in Java or **std::vector** in C++.Here's a breakdown of how an array-based list works and how items can be added or removed from various positions (head, tail, and center):

#### 1\. **Array-Based List Characteristics**

**Indexed Access**: Each element in the array can be accessed directly by its index (position). Accessing an element by index is **O(1)**, which makes array-based lists very fast for lookups.**Fixed Size or Dynamic Resize**: If the array is full, a larger array is allocated, and the old elements are copied over. This resizing typically happens by doubling the size of the array to accommodate future insertions.**Efficient Append (At the Tail)**: Adding or removing elements at the **tail** is efficient, usually **O(1)** in the amortized sense.**Inefficient Insertions/Removals in the Middle/Head**: If you insert or remove elements at the **head** or in the **middle**, it can be inefficient because it requires shifting the existing elements to make room for the new item or to close the gap. This takes **O(n)** time, where n is the number of elements in the list.nn

#### 2\. **Operations on Array-Based List**

Here’s how you can add or remove elements from the head, tail, or center of an array-based list:

#### a. **Add to the Tail**

Append an element at the end of the array. If there's enough space, it simply goes to the next available index.**Time Complexity**: O(1) if no resizing is needed, O(n) if resizing occurs.O(1)O(1)O(n)

#### b. **Remove from the Tail**

Remove the last element in the array. You can just decrease the size or set the element to null/0/undefined.**Time Complexity**: O(1).O(1)

#### c. **Add to the Head**

To insert at the head, you need to shift all elements one position to the right to make room for the new element.**Time Complexity**: O(n).O(n)

#### d. **Remove from the Head**

Similar to insertion at the head, removing an element from the head requires shifting all the elements one position to the left.**Time Complexity**: O(n).O(n)

#### e. **Add to the Center**

To insert at the middle (or any arbitrary index), you must shift all elements to the right from that index to the end to make room for the new element.**Time Complexity**: O(n), as shifting is required.O(n)

#### f. **Remove from the Center**

Similar to inserting, you must shift elements to the left from the point of removal to close the gap.**Time Complexity**: O(n).
