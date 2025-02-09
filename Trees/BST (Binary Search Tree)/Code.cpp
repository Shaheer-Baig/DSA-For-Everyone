#include <iostream>
#include <queue>
using namespace std;

class Node {

public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}

};

// Level-order traversal with level separation
void levelOrderTraversal(Node* root) {
	if (root == NULL) return;

	queue<Node*> q; // Create a queue for level-order traversal.
	q.push(root);   // Push the root node into the queue.
	q.push(NULL);   // Add a NULL marker to indicate the end of the first level.

	while (!q.empty()) {
		Node* temp = q.front(); // Access the front node.
		q.pop();

		if (temp == NULL) { // End of the current level.
			cout << endl;   // Print a newline to separate levels.

			if (!q.empty()) {
				q.push(NULL); // Add a NULL marker for the next level.
			}
		}
		else {
			cout << temp->data << " "; // Print the current node's data.

			// Push the left and right children (if they exist) into the queue.
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}
}

// Insert into BST
Node* InsertIntoBST(Node* root, int d) {
	// Base case: insert the node when reaching a NULL spot.
	if (root == NULL) {
		root = new Node(d);
		return root;
	}

	// Traverse to the correct subtree.
	if (d > root->data) {
		// Insert at right
		root->right = InsertIntoBST(root->right, d);
	}
	else {
		// Insert at left
		root->left = InsertIntoBST(root->left, d);
	}
	return root;
}

// Function to take input until -1 is entered.
void takeInput(Node*& root) {
	int data;
	cin >> data;

	while (data != -1) {
		root = InsertIntoBST(root, data);
		cin >> data;
	}
}

// In-order traversal
void inorder(Node* root) {
	// Base case
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// Pre-order traversal
void preorder(Node* root) {
	// Base case
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

// Post-order traversal
void postorder(Node* root) {
	// Base case
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

// Recursive search in BST
bool searchInBST(Node*& root, int value) {
	// Base case: root is NULL or the value is found.
	if (root == NULL) {
		return false;
	}
	if (root->data == value) {
		return true;
	}

	// Traverse the appropriate subtree.
	if (root->data > value) {
		// Go left
		return searchInBST(root->left, value);
	}
	else {
		// Go right
		return searchInBST(root->right, value);
	}
}

// Iterative search in BST
bool searchInBST2(Node*& root, int value) {
	Node* temp = root;

	while (temp != NULL) {
		if (temp->data == value) {
			return true;
		}
		if (temp->data > value) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return false;
}

// Function to find the minimum value in the BST
Node* Minvalue(Node* root) {
	Node* temp = root;

	// If the tree is empty, return NULL and print a message.
	if (root == NULL) {
		cout << "The tree is empty." << endl;
		return NULL;
	}

	// Traverse left until the smallest value is found.
	while (temp->left != NULL) {
		temp = temp->left;
	}

	// Return the node with the smallest value.
	return temp;
}

// Function to find the maximum value in the BST
Node* Maxvalue(Node* root) {
	Node* temp = root;

	// If the tree is empty, return NULL and print a message.
	if (root == NULL) {
		cout << "The tree is empty." << endl;
		return NULL;
	}

	// Traverse right until the largest value is found.
	while (temp->right != NULL) {
		temp = temp->right;
	}

	// Return the node with the largest value.
	return temp;
}

// Delete a node from the BST
Node* deleteFromBST(Node* root, int value) {
	//Base case: if the root is NULL
	if (root == NULL)
		return root;

	if (root->data == value) {
		// Case 1: Node with 0 children
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}

		// Case 2: Node with 1 child
		if (root->left != NULL && root->right == NULL) { // Left child only
			Node* temp = root->left;
			delete root;
			return temp;
		}

		if (root->left == NULL && root->right != NULL) { // Right child only
			Node* temp = root->right;
			delete root;
			return temp;
		}

		// Case 3: Node with 2 children
		if (root->left != NULL && root->right != NULL) {
			// Find the maximum value in the left subtree
			Node* maxNode = Maxvalue(root->left);
			root->data = maxNode->data;

			// Recursively delete the inorder predecessor
			root->left = deleteFromBST(root->left, maxNode->data);
			return root;
		}
	}
	else if (root->data > value) {
		// Go to the left subtree
		root->left = deleteFromBST(root->left, value);
		return root;
	}
	else {
		// Go to the right subtree
		root->right = deleteFromBST(root->right, value);
		return root;
	}
}

int main() {
	// Input: 10 8 21 7 27 5 4 3 -1
	Node* root = NULL;
	cout << "Enter data to create BST" << endl;
	takeInput(root);


	//deletion
	root = deleteFromBST(root, 7);

	cout << "Printing the BST" << endl;;
	levelOrderTraversal(root);

	cout << "Printing Inorder: " << endl;
	inorder(root);

	cout << endl << "Printing Preorder: " << endl;
	preorder(root);

	cout << endl << "Printing Postorder: " << endl;
	postorder(root);

	cout << endl << "Enter a value to search in BST: ";
	int value;
	cin >> value;

	if (searchInBST(root, value)) {
		cout << "Value " << value << " FOUND in the BST." << endl;
	}
	else {
		cout << "Value " << value << " NOT found in the BST." << endl;
	}

	cout << endl << "Enter a value to search in BST: ";
	int value2;
	cin >> value2;

	if (searchInBST2(root, value2)) {
		cout << "Value " << value2 << " FOUND in the BST." << endl;
	}
	else {
		cout << "Value " << value2 << " NOT found in the BST." << endl;
	}

	// Display max value
	cout << "The Min value in the tree is: " << Minvalue(root)->data << endl;

	//Display min value
	cout << "The Max value in the tree is: " << Maxvalue(root)->data << endl;

	

}
