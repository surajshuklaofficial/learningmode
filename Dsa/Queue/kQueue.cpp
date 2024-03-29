#include<iostream>
#include<climits>
using namespace std;

class kQueues
{ 
	int *arr;
	int *front; 
	int *rear; 	 
	int *next; 
	int n, k;

	int freeSport;

public:
	kQueues(int k, int n);
	bool isFull() { return (freeSport == -1); }
	void enqueue(int item, int qn);
	int dequeue(int qn);
	bool isEmpty(int qn) { return (front[qn] == -1); }
};

kQueues::kQueues(int k1, int n1)
{
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];

	for (int i = 0; i < k; i++) front[i] = -1;

	for (int i=0; i<n-1; i++) next[i] = i+1;
	next[n-1] = -1;

	freeSport = 0;
}

void kQueues::enqueue(int item, int qn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nQueue Overflow\n";
		return;
	}

    // Store index of first freeSport slot
	int i = freeSport;	 

	// Update index of freeSport slot to index of next slot in freeSport list
	freeSport = next[i];

    // connecting prev rear with new rear (if there is first element) or intialize new queue
	if (isEmpty(qn))
		front[qn] = i;
	else
		next[rear[qn]] = i;

    // it will help when last element is removed and we have to make front and rear -1 again
	next[i] = -1; 

	// Update next of rear and then rear for queue number 'qn'
	rear[qn] = i;

	// Put the item in array
	arr[i] = item;
}

int kQueues::dequeue(int qn)
{
	// Underflow checkSAS
	if (isEmpty(qn))
	{
		cout << "\nQueue Underflow\n";
		return INT_MAX;
	}

	// Find index of front item in queue number 'qn'
	int i = front[qn];

	// Change top to store next of previous top
	front[qn] = next[i]; 

	// Attach the previous front to the
	// beginning of freeSport list
	next[i] = freeSport;
	freeSport = i;

	return arr[i];
}

int main()
{
	// Let us create 3 queue in an array of size 10
	int k = 3, n = 10;
	kQueues ks(k, n);

	// Let us put some items in queue number 2
	ks.enqueue(15, 2);
	ks.enqueue(45, 2);

	// Let us put some items in queue number 1
	ks.enqueue(17, 1);
	ks.enqueue(49, 1);
	ks.enqueue(39, 1);

	// Let us put some items in queue number 0
	ks.enqueue(11, 0);
	ks.enqueue(9, 0);
	ks.enqueue(7, 0);

	ks.dequeue(0);
	ks.dequeue(0);
	ks.dequeue(0);

	ks.enqueue(2, 0);

	cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

	return 0;
}
