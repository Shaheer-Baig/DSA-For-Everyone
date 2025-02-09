#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* root) {
    if (!root) {
        return 0;
    }
    return root->height;
}

int getBalance(Node* root) {
    return getHeight(root->left) - getHeight(root->right);
}

// Function to display tree structure (level-order traversal)
void displayTree(Node* root) {
    if (!root) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at current level
        while (levelSize--) {
            Node* node = q.front();
            q.pop();

            cout << node->data << "(" << getBalance(node) << ") ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl; // Move to next level
    }
    cout << "---------------------------------" << endl;
}

// Right Rotation
Node* rightRotation(Node* root) {
    Node* child = root->left;
    Node* childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    cout << "Performed Right Rotation at node " << root->data << endl;
    displayTree(child);

    return child;
}

// Left Rotation
Node* leftRotation(Node* root) {
    Node* child = root->right;
    Node* childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    cout << "Performed Left Rotation at node " << root->data << endl;
    displayTree(child);

    return child;
}

// Insert function
Node* insert(Node* root, int data) {
    // Doesn't exist
    if (!root)
        return new Node(data);

    // If there is already a node
    if (data < root->data) // Left Side
        root->left = insert(root->left, data);
    else if (data > root->data) { // Right Side
        root->right = insert(root->right, data);
    }
    else
        return root; // Duplicate Elements Not Allowed

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balancing check
    int balance = getBalance(root);

    // When balancing factor is >1
    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotation(root);

    // Left Right Case
    else if (balance > 1 && data > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // When balancing factor is <-1
    // Right Right Case
    else if (balance < -1 && data > root->right->data) {
        return leftRotation(root);
    }

    // Right Left Case
    else if (balance < -1 && data < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    // No Unbalancing
    else {
        return root;
    }
}

// Traversals
void preorder(Node* root) {
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int findClosestValue(Node* root, int target) {
    if (!root)
        return INT_MAX; // If tree is empty, return a very large value (impossible in a typical AVL scenario)

    int closest = root->data; // Start with the root's value as the closest
    Node* current = root;

    while (current) {
        // Update closest if the current value is closer to the target
        if (abs(target - current->data) < abs(target - closest)) {
            closest = current->data;
        }

        // Traverse the tree based on the target value
        if (target < current->data)
            current = current->left; // Move to the left subtree
        else if (target > current->data)
            current = current->right; // Move to the right subtree
        else
            break; // Exact match found
    }

    return closest;
}
int rangeSum(Node* root, int low, int high) {
    if (!root)
        return 0; // Base case: empty tree

    // If the current node's value is within the range, add it to the sum
    if (root->data >= low && root->data <= high)
        return root->data + rangeSum(root->left, low, high) + rangeSum(root->right, low, high);

    // If the current node's value is smaller than the range, skip the left subtree
    if (root->data < low)
        return rangeSum(root->right, low, high);

    // If the current node's value is larger than the range, skip the right subtree
    return rangeSum(root->left, low, high);
}

// Helper function to find the k-th smallest element
void kthSmallestUtil(Node* root, int& k, int& result) {
    if (!root || k <= 0)
        return;

    // Traverse the left subtree
    kthSmallestUtil(root->left, k, result);

    // Decrement k and check if the current node is the k-th smallest
    k--;
    if (k == 0) {
        result = root->data;
        return;
    }

    // Traverse the right subtree
    kthSmallestUtil(root->right, k, result);
}

// Main function to find k-th smallest element
int kthSmallest(Node* root, int k) {
    int result = -1; // Default value if k is out of range
    kthSmallestUtil(root, k, result);
    return result;
}



int main()
{
    Node* root = NULL;

    // Insert elements into the AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Final Tree (Level-order): " << endl;
    displayTree(root);

    // Find the closest value to a target
    int target;
    cout << "Which Numbers closest value you are looking for? " << endl;
    cin >> target;
    if (int closestValue = findClosestValue(root, target))
    {
        cout << "The closest value to " << target << " is " << closestValue << "." << endl;

    }
    else {
        cout << "Sorry you entered an incorrect number" << endl;
    }
    int low, high;
    cout << "Enter the range of your number" << endl;
    cout << "Enter the low number" << endl;
    cin >> low;
    cout << "Enter the high number" << endl;
    cin >> high;
   
    int sum = rangeSum(root, low, high);
    cout << "The sum of all nodes in the range [" << low << ", " << high << "] is " << sum << "." << endl;

    // Find the k-th smallest element
    int k;
    cout << "Which kth lowest number are you looking for? " << endl;
    cout << "Enter the kth lowest value you want to find" << endl;
   
    cin >> k;

    int kthSmallestValue = kthSmallest(root, k);
    if (kthSmallestValue != -1)
        cout << "The " << k << "rd smallest element is " << kthSmallestValue << "." << endl;
    else
        cout << "Invalid value of k!" << endl;


    return 0;
}
