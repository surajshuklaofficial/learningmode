#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Node {
    int data;
    Node* left;
    Node* right;
} Node;

Node* createNode(int data, Node* current) {
    if (current == NULL) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        if (newNode == NULL){
            printf("memory allocation failed\n");
            exit(1);
        }
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else if (current->data <  data) {
        current->right = createNode(data, current->right);
    } else {       
        current->left = createNode(data, current->left);
    }
    return current;
}

void inorder(Node* current){
    if (current->left != NULL) {
        inorder(current->left);
    } 

    printf("%d ", current->data);

    if (current->right != NULL) {
        inorder(current->right);
    }
}

Node* traverse(Node* current, int data) {
    if (current->data == data) {
        return current;
    } else if (current->data < data) {
        return traverse(current->right, data);
    } else if  (current->data > data){
        return traverse(current->left, data);
    } else return NULL;
}   

void delete_leaf_node(Node* current, Node* node_to_be_deleted){
    if (current->left == node_to_be_deleted) {
        current->left = NULL;
    } else if (current->right == node_to_be_deleted){
        current->right = NULL;
    } else {
        if (current->data < node_to_be_deleted->data) {
            delete_leaf_node(current->right, node_to_be_deleted);
        } else if (current->data > node_to_be_deleted->data) {
            delete_leaf_node(current->left, node_to_be_deleted);
        }
    }
}

void delete_node_with_one_child(Node* current, Node* node_to_be_deleted){
    if (current->left == node_to_be_deleted) {
        current->left = (node_to_be_deleted->left != NULL) ? node_to_be_deleted->left : node_to_be_deleted->right;
    } else if (current->right == node_to_be_deleted){
        current->right = (node_to_be_deleted->left != NULL) ? node_to_be_deleted->left : node_to_be_deleted->right;
    } else {
        if (current->data < node_to_be_deleted->data) {
            delete_node_with_one_child(current->right, node_to_be_deleted);
        } else if (current->data > node_to_be_deleted->data) {
            delete_node_with_one_child(current->left, node_to_be_deleted);
        }
    }
}

Node* smallest_node(Node* current) {
    if (current->left != NULL) {
        smallest_node(current->left);
    } else return current;
};

void deleteNode(Node* root, int data) {
    Node *node_to_be_delete = traverse(root, data);

    if (node_to_be_delete->left == NULL && node_to_be_delete->right == NULL) {
        delete_leaf_node(root, node_to_be_delete);
    } else if (node_to_be_delete->left == NULL || node_to_be_delete->right == NULL) {
        delete_node_with_one_child(root, node_to_be_delete);
    } else {
        Node *smallestNode = smallest_node(node_to_be_delete->right);
        node_to_be_delete->data = smallestNode->data;
        delete_leaf_node(node_to_be_delete, smallestNode);
    }
}

int main() {

    Node *root;
    root = createNode(56, NULL);
    createNode(34, root);
    createNode(67, root);
    createNode(17, root);
    createNode(35, root);
    createNode(15, root);
    // createNode(, root);
    // createNode(17, root);
    
    printf("%p\n", root);
    // printf("%p\n", root->left);
    // printf("%p\n", root->right);
    // printf("%d\n", root->left->data);
    // printf("%d\n", root->right->data);
    // printf("%d\n", root->left->right->data);

    //inorder
    printf("inorder:\n");
    inorder(root);

    //traverse
    printf("\ntraverse: %p\n", traverse(root, 56));
    printf("traverse: %d\n", traverse(root, 56)->data);

    // smallest node
    printf("smallest node: %d\n", smallest_node(root)->data);

    // deleting node
    deleteNode(root, 34);

    inorder(root);
    
}