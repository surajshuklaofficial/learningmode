#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
};

Node *buildTree(Node *root) {
    root = new Node();

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root->data = data;
    
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root) {
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node *front = q.front();
        q.pop();
    
        if (front == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        }

        else {
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
            cout << front->data << " ";
        }

    }
    cout << endl;
}

void inOrderTraversal(Node *root) {
    if (root->left) inOrderTraversal(root->left);

    cout << root->data << " ";

    if (root->right) inOrderTraversal(root->right);

}

void postOrderTraversal(Node *root) {
    if (root->left) postOrderTraversal(root->left);

    if (root->right) postOrderTraversal(root->right);

    cout << root->data << " ";
}

void preOrderTraversal(Node *root) {
    cout << root->data << " ";

    if (root->left) preOrderTraversal(root->left);

    if (root->right) preOrderTraversal(root->right);
}

Node *createNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *buildTreeFromLevelOrder(int arr[], int size) {
    queue<Node *> q;
    int pointer = 0;

    Node* root = createNode(arr[pointer]);
    pointer++;
    q.push(root);

    while (pointer < size && !q.empty()) {
            Node *front = q.front();
            q.pop();
            cout << front->data << endl;
            front->left = createNode(arr[pointer]);
            q.push(front->left);
            pointer++;
            if (pointer == size) break;

            front->right = createNode(arr[pointer]);
            q.push(front->right);
            pointer++;
            if (pointer == size) break;
    }

    return root;
}

// 1 3 7 -1 -1 8 -1 -1 5 11  -1 -1 -1
int main() {
    Node *root;
    
    root = NULL;

    // root = buildTree(root);

    int arr[] = {1, 3, 5, 7, 8, 11, 12 , 13};

    root = buildTreeFromLevelOrder(arr, 8);

    // cout << root->left->data << endl;
    levelOrderTraversal(root);

    // inOrderTraversal(root);
    // cout << endl;
    // postOrderTraversal(root);
    // cout << endl;
    // preOrderTraversal(root);
    // cout << endl;
    return 0;
}