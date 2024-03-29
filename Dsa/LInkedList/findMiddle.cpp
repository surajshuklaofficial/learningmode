#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *findMiddle(Node *head)
{
    Node *slowpointer = head;
    Node *fastpointer = head;

    while (fastpointer != nullptr && fastpointer->next != nullptr)
    {
        fastpointer = fastpointer->next->next;
        slowpointer = slowpointer->next;
    }

    return slowpointer;
}

int main()
{

    return 0;
}