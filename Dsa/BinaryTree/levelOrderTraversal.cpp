#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

void levelOrderTraversal1(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
            cout << front->data << " ";
        }
    }
    cout << endl;
}

vector<int> levelOrderTraversal2(Node *root)
{
    vector<int> result;
    queue<Node *> t;
    t.push(root);

    while (!t.empty())
    {
        int size = t.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node *current = t.front();
            t.pop();

            result.push_back(current->data);
            
            if (current->left)
                t.push(current->left);
            if (current->right)
                t.push(current->right);
        }
    }

    return result;
}

int main()
{

    return 0;
}