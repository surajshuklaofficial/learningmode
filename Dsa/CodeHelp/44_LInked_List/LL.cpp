#include <iostream>
using namespace std;

template <class T>
class Node {
    T data;
    Node *next;
    Node *prev;

    Node (T data) {
        this->data = data;
        next = nullptr;
    }

    template <class U>
    friend class SinglyLL;

    template<class S>
    friend class CircularLL;

    template<class S>
    friend class DoublyLL;
};

template <class T>
class LinkedList {
    protected:
        virtual void insertAtbeginning(T data) = 0;
        virtual void insertAtEnd(T data) {};
        virtual void insertAtPos(T data, int pos){};
        virtual T deleteNodebyVal(T data){};
        virtual T deleteNodebyPos(int pos){};
};

/* here you can see I have made virtual functions protected in parent but not in derived but there final behaviour is public*/
template <class T>
class SinglyLL : protected LinkedList<T> {
    Node<T> *head;
    public: 
        SinglyLL() : head(nullptr) {}

        void insertAtbeginning(T data) {
            Node<T>* temp = new Node<T>(data);
            temp->next = head;
            head = temp;
        }

        void insertAtEnd(T data) {
            if (head == nullptr) {
                head = new Node<T>(data);
                
            } else {
                Node<T> *current = head;
                while (current->next != nullptr) current = current->next;

                Node<T> *temp = new Node<T>(data);
                current->next = temp;
            }
        }

        // overflow condition is not handled
        void insertAtPos(T data, int pos) {
            Node<T> *current = head;
            if (pos == 1) {
                insertAtbeginning(data);
                return;
            }
            for (int i = 1; i < pos - 1; i++, current = current->next) {}
            Node<T> *temp = new Node<T>(data);
            temp->next = current->next;
            current->next = temp;
        }

        T deleteNodebyVal(T data) {
            Node<T> *current = head, *temp;

            if (head->data == data) {
                head = head->next;
                T stored_data = current->data;
                delete current;
                return stored_data;
            }

            while(current != nullptr) {
                if (current->data == data) {
                    temp->next = current->next;
                    T stored_data = current->data;
                    delete current;
                    return stored_data;
                }
                temp = current;
                current = current->next;
            }
        }

        // overflow condition is not handled
        T deleteNodebyPos(int pos) {
            Node<T> *current = head, *temp;

            if (pos == 1) {
                head = head->next;
                T stored_data = current->data;
                delete current;
                return stored_data;
            }

            for (int i = 1; i < pos - 1; i++) current = current->next;

            temp = current->next;
            T stored_data = temp->data;
            current->next = temp->next;
            delete temp;
            return stored_data;
        }

        void display() {
            for (Node<T> *current = head; current != nullptr; current = current->next) cout << current->data << " ";
            cout << endl;
        };
};


template <class T>
class CircularLL : protected LinkedList<T> {
    Node<T> *head;
    Node<T> *tail;
    public:
        CircularLL() : head(nullptr), tail(nullptr) {}
        void insertAtbeginning(T data) {
            Node<T>* temp = new Node<T>(data);
            temp->next = head;
            head = temp;
            if (tail == nullptr) tail = head;
            tail->next = head;
        }
        void display() {
            if (head == nullptr) {
                cout << "Empty LL!" << endl;
                return;
            }
            Node<T> *current = head;
            for (; current != tail; current = current->next) cout << current->data << " ";
            cout << current->data << endl;
        };

        void insertAtPos(T data, int pos) {
            Node<T> *current = head;
            if (pos == 1) {
                insertAtbeginning(data);
                return;
            }
            for (int i = 1; i < pos - 1; i++, current = current->next) {}
            Node<T> *temp = new Node<T>(data);
            temp->next = current->next;
            current->next = temp;
        }

        T deleteNodebyVal(T data) {
            Node<T> *current = head, *temp;

            if (head->data == data) {
                head = head->next;
                tail->next = head;
                T stored_data = current->data;
                delete current;
                return stored_data;
            }

            current = current->next;
            while(current != head) {
                if (current->data == data) {
                    temp->next = current->next;
                    tail = temp;
                    T stored_data = current->data;
                    delete current;
                    return stored_data;
                }
                temp = current;
                current = current->next;
            }
        }

        // overflow condition is not handled
        T deleteNodebyPos(int pos) {
            Node<T> *current = head, *temp;

            if (pos == 1) {
                head = head->next;
                tail->next = head;
                T stored_data = current->data;
                delete current;
                return stored_data;
            }

            for (int i = 1; i < pos - 1; i++) current = current->next;

            temp = current->next;
            T stored_data = temp->data;
            current->next = temp->next;
            if (temp == tail) tail = current;
            delete temp;
            return stored_data;
        }

};


template <class T>
class DoublyLL : protected LinkedList<T> {

    Node<T> *head;
    public: 
        DoublyLL(): head(nullptr) {};

        void insertAtbeginning(T data) {
            Node<T>* temp = new Node<T>(data);
            temp->next = head;
            temp->prev = nullptr;
            head = temp;
        }

        void insertAtEnd(T data) {
            if (head == nullptr) {
                head = new Node<T>(data);
                
            } else {
                Node<T> *current = head;
                while (current->next != nullptr) current = current->next;

                Node<T> *temp = new Node<T>(data);
                current->next = temp;
                temp->prev = current; // maybe temp->next = nullptr; not sure though
            }
        }

        // overflow condition is not handled
        void insertAtPos(T data, int pos) {
            Node<T> *current = head;
            if (pos == 1) {
                insertAtbeginning(data);
                return;
            }
            for (int i = 1; i < pos - 1; i++, current = current->next) {}
            Node<T> *temp = new Node<T>(data);
            temp->next = current->next;
            current->next = temp;

            current->next->prev = temp;
            temp->prev = current;
        }
        
        T deleteNodebyVal(T data) {
            Node<T> *current = head, *temp;

            if (head->data == data) {
                head = head->next;
                head->prev = nullptr;
                T stored_data = current->data;
                delete current;
                return stored_data;
            }

            while(current != nullptr) {
                if (current->data == data) {
                    temp->next = current->next;
                    if (current->next) current->next->prev = temp;
                    T stored_data = current->data;
                    delete current;
                    return stored_data;
                }
                temp = current;
                current = current->next;
            }
        }

        // overflow condition is not handled
        T deleteNodebyPos(int pos) {
            Node<T> *current = head, *temp;

            if (pos == 1) {
                head = head->next;
                head->prev = nullptr;
                T stored_data = current->data;
                delete current;
                return stored_data;
            }

            for (int i = 1; i < pos - 1; i++) current = current->next;

            temp = current->next;
            T stored_data = temp->data;
            current->next = temp->next;
            if (temp->next) temp->next->prev = current;
            delete temp;
            return stored_data;
        }

        void display() {
            for (Node<T> *current = head; current != nullptr; current = current->next) cout << current->data << " ";
            cout << endl;
        };
};

int main() {
    
    // SinglyLL<int> S1;
    // S1.insertAtbeginning(5);
    // S1.insertAtbeginning(3);
    // S1.insertAtbeginning(4);
    // S1.insertAtEnd(9);
    // S1.insertAtPos(7, 5);

    // S1.display();
    // cout << S1.deleteNodebyPos(3) << endl;
    // S1.display();

    // CircularLL<int> C1;
    // C1.insertAtbeginning(5);
    // C1.insertAtbeginning(3);
    // C1.insertAtbeginning(4);
    // C1.insertAtPos(7, 1);

    // C1.display();
    // // cout << C1.deleteNodebyPos(4) << endl;
    // // C1.display();
    // cout << C1.deleteNodebyVal(5) << endl;
    // C1.display();

    DoublyLL<int> D1;
    D1.insertAtbeginning(3);
    D1.insertAtbeginning(4);
    D1.insertAtbeginning(5);
    D1.insertAtEnd(1);
    D1.insertAtPos(7, 5);

    D1.display();

    cout << D1.deleteNodebyVal(7) << endl;

    D1.display();
    return 0;
}