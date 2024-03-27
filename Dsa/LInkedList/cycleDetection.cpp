#include <iostream>
#include <map>
using namespace std;

template <class T>
class SinglyListNode
{
public:
    SinglyListNode<T> *next;
    T data;
};

// using maps
// bool detectCycle(SinglyListNode<int> *head) {
//     map<SinglyListNode<int>*, bool> visited;

//     SinglyListNode<int> *current = head;
//     while (current != nullptr && visited[current] != true) {
//         visited[current] = true;
//         current = current->next;
//     }

//     if (visited[current] == true) return true;
//     if (current == nullptr) return false;
// }

// floyd's cycle detection algorithm
bool detectCycle(SinglyListNode<int> *head)
{
    SinglyListNode<int> *slow_pointer = head;
    SinglyListNode<int> *fast_pointer = head;
    do
    {
        slow_pointer = slow_pointer->next;
        if (fast_pointer->next != nullptr)
            fast_pointer = fast_pointer->next->next;
        else
            return false;

    } while (slow_pointer != fast_pointer && fast_pointer != nullptr);

    if (fast_pointer == nullptr)
        return false;
    else
        return true; // slow_pointer == fast_pointer
}

// detect start node of loop
SinglyListNode<int> *findStartingNode(SinglyListNode<int> *head)
{
    SinglyListNode<int> *slow_pointer = head;
    SinglyListNode<int> *fast_pointer = head;
    do
    {
        slow_pointer = slow_pointer->next;
        if (fast_pointer->next != nullptr)
            fast_pointer = fast_pointer->next->next;
        else
            return nullptr;

    } while (slow_pointer != fast_pointer && fast_pointer != nullptr);

    if (fast_pointer == nullptr)
        return nullptr;
    else
    { // slow_pointer == fast_pointer => loop exists
        slow_pointer = head;

        while (slow_pointer != fast_pointer)
        {
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next;
        }

        return slow_pointer;
    }
}

void removeLoop(SinglyListNode<int> *head)
{
    SinglyListNode<int> *temp = findStartingNode(head);

    if (temp == nullptr)
    {
        cout << "No cycle exists!" << endl;
    }
    else
    {
        SinglyListNode<int> *current = temp;
        while (current->next != temp)
            current = current->next;
        current->next = nullptr;
    }
}

int main()
{

    SinglyListNode<int> *head = new SinglyListNode<int>();

    head->data = 1;
    head->next = new SinglyListNode<int>();
    head->next->data = 2;
    head->next->next = new SinglyListNode<int>();
    head->next->next->data = 3;
    head->next->next->next = new SinglyListNode<int>();
    head->next->next->next->data = 4;
    head->next->next->next->next = new SinglyListNode<int>();
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = head;

    // cout << head->next->next->next->next->next->data << endl;

    SinglyListNode<int> *temp = findStartingNode(head);
    if (temp == nullptr)
    {
        cout << "No Cycle Present!" << endl;
    }
    else
    {
        cout << temp->data << endl;
    }

    removeLoop(head);
    SinglyListNode<int> *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // cout << detectCycle(head) << endl;
    return 0;
}