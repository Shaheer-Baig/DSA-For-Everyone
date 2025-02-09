#include <iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }

};


//tree building technique 1
node*buildTree(node*root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    //contructor will be called 
    root = new node(data);
    
    // Base case: if input is -1, return NULL
        if (data == -1) {
        return NULL;
    }
        // Recursive calls for left and right children
    cout << "Enter data for inserting in left of " <<data<< endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node* root) {
    if (root == NULL) return; // Edge case: empty tree

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Mark the end of the first level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // Current level finished
            cout << endl;

            if (!q.empty()) {
                // If there are still nodes to process, add a new NULL marker
                q.push(NULL);
            }
        }
        else {
            // Print current node's data
            cout << temp->data << " ";

            // Push children (if any) into the queue
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

//tree building through level order building
void buildFromLevelOrder(node*& root) {
    queue<node*> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1) {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1) {
            temp->left = new node(rightdata);
            q.push(temp->right);
        }
    }
}


void inorder(node* root) {
//base case
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data<<" ";
    inorder(root->right);
}
void preorder(node* root) {
    //base case
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    
    preorder(root->right);
}

void postorder(node* root) {
    //base case
    if (root == NULL) {
        return;
    }
    
    postorder(root->left);

    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    
    //creating a tree
    root = buildTree(root);
    cout << "Printing tre level order traversal output: " << endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal is: " << endl;;
    inorder(root);

    cout <<endl<< "Preorder traversal is: " << endl;
    preorder(root);

    cout << endl << "Postorder traversal is: " << endl;
    postorder(root);
}

