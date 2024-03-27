#include <iostream>
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *current = head;
    LinkedListNode<int> *prevNode = nullptr;
    LinkedListNode<int> *temp;
    while (current != nullptr)
    {
        temp = current->next;
        current->next = prevNode;
        prevNode = current;
        current = temp;
    }
    return prevNode;
}

LinkedListNode<int> *reverseLinkedListR(LinkedListNode<int> *current, LinkedListNode<int> *prevNode)
{   
    if (current->next == nullptr) return current;

    LinkedListNode<int> *newHead = reverseLinkedListR(current->next, current);
    current->next = prevNode;

    return newHead;
}

int main()
{
    return 0;
}