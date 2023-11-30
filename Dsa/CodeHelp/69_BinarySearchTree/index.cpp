#include <iostream>
using namespace std;

class BinarySearchTree {

    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val): data(val), left(nullptr), right(nullptr) {};
    };

    
    Node* insertNode(Node* root, int data) {
        if (root == NULL) {
            Node* newNode = new Node(data);
            return newNode;
        }

        if (data <= root->data)
            root->left = insertNode(root->left, data);
        else
            root->right = insertNode(root->right, data);

        return root;
    }
public:
    Node* root;
    

    BinarySearchTree() : root(nullptr) {};

    void insertNode(int data) {
        root = insertNode(root, data);
    }

    void inOrderTraversal(Node* root) {
        if (root->left)
            inOrderTraversal(root->left);

        cout << root->data << " ";

        if (root->right)
            inOrderTraversal(root->right);
    }

    int minVal(Node *root) {
        while (root->left != nullptr) {
            root = root->left;
        }

        return root->data;
    } 

    Node *deleteNode(Node *root, int val) {
        if (root->data == val) {
            // 0 child
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }

            // 1 child
            else if (root->left == nullptr && root->right != nullptr) {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            else if (root->left != nullptr && root->right == nullptr) {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            
            // 2 child
            else {
                int min = minVal(root->right);
                root->data = min;
                root->right = deleteNode(root->right, min);
                return root;
            }
        }
        else if (root->data < val) root->right = deleteNode(root->right, val);
        else root->left = deleteNode(root->left, val);

        return root;
    }
    
};

int main() {

    BinarySearchTree B;

    B.insertNode(10);
    B.insertNode(3);
    B.insertNode(4);
    B.insertNode(15);
    B.insertNode(6);
    B.insertNode(1);
    B.insertNode(14);
    B.insertNode(16);
    B.insertNode(17);

    
    B.inOrderTraversal(B.root);
    cout << endl;
    B.deleteNode(B.root, 15);
    B.inOrderTraversal(B.root);

    return 0;
}
