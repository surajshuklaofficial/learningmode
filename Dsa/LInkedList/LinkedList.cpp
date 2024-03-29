#include <iostream>
using namespace std;

template <class T>
class LinkedList;

template <class T>
class SinglyListNode
{
    SinglyListNode<T> *next;
    T data;

    friend class LinkedList<T>;
};

template <class T>
class LinkedList
{
    SinglyListNode<T> *head;

public:
    LinkedList() : head(nullptr) {}

    LinkedList(T data)
    {
        head = new SinglyListNode<T>();
        head->next = nullptr;
        head->data = data;
    }

    void insert(T data)
    {
        SinglyListNode<T> *newNode = new SinglyListNode<T>();
        newNode->next = head;
        newNode->data = data;
        head = newNode;
    }

    void traverse()
    {
        SinglyListNode<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    SinglyListNode<int> *solve(SinglyListNode<int> *current, SinglyListNode<int> *prevNode)
    {
        if (current->next == nullptr)
            return current;

        SinglyListNode<int> *newHead = solve(current->next, current);
        current->next = prevNode;

        return newHead;
    }

    void *reverseLinkedList()
    {
        // if (head == nullptr)
        //     return head;
        SinglyListNode<int> *prevNode = nullptr;

        head = solve(head, prevNode);
    }

    void removeDuplicates()
    {
        SinglyListNode<T>  *current = head;

        while (current != nullptr)
        {
            SinglyListNode<T> *successive_current = current;
            while (successive_current->next != nullptr)
            {
                if (successive_current->next->data == current->data)
                {
                    successive_current->next = successive_current->next->next;
                }
                successive_current = successive_current->next;
            }
            current = current->next;
        }
    }
};

int main()
{

    LinkedList<int> *L1 = new LinkedList<int>();

    L1->insert(5);
    L1->insert(3);
    L1->insert(2);
    L1->insert(3);
    L1->insert(4);
    L1->insert(3);

    L1->traverse();

    L1->removeDuplicates();
    L1->traverse();

    delete L1;
    return 0;
}