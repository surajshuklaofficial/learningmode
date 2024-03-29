#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node* nextNode, Node* childNode) : data(x), next(nextNode), child(childNode) {}
};

void printFlattenedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* flattenLinkedList(Node* head) {
    Node *current = head;
    Node *prevNode = nullptr;
    while (current != nullptr) {
        Node *temp = current->next;
        current->next = current->child;
        
        current->child = nullptr;
        current = current->next;

        while (current != nullptr) {
            current->next = current->child;
            current->child = nullptr;
            prevNode = current;
            current = current->next;
        }
        prevNode->next = temp;
        current = temp;
    }   

    return head;
}

int main() {
    // Create a sample linked list with child pointers
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(7);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(20);

    head->child = new Node(2);
    head->child->child = new Node(3);

    head->next->child = new Node(5);
    head->next->child->child = new Node(6);

    head->next->next->child = new Node(8);

    head->next->next->next->child = new Node(12);
            
    // Flatten the linked list
    printFlattenedList(head);
    head = flattenLinkedList(head);

    // Print the flattened linked list
    printFlattenedList(head);

    return 0;
}
