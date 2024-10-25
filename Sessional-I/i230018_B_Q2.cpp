#include<iostream>

using namespace std;

class Queue
{
private:
	struct Node
	{
		int person;
		Node* next;
	};
	Node* front;
	Node* rear;

public:
	Queue()
	{
		front = rear = NULL;
	}

	// Enqueues a person in the queue
	void enqueue(int _person)
	{
		if (front == NULL)
		{
			Node* newNode = new Node;
			newNode->person = _person;
			newNode->next = NULL;
			front = rear = newNode;
			return;
		}

		Node* newNode = new Node;
		newNode->person = _person;
		newNode->next = NULL;
		rear->next = newNode;
		rear = newNode;
	}

	//  Returns if the queue is empty
	bool isEmpty()
	{
		return front == NULL;
	}

	// Dequeues a person from the queue
	int dequeue()
	{
		if (isEmpty())
			return -1;

		Node* temp = front;
		int data = front->person;

		front = front->next;
		delete temp;

		if (front == NULL)
			rear = front;

		return data;
	}

	// Prints the people in the queue
	void print()
	{
		Node* current = front;

		while (current)
		{
			cout << current->person << " ";
			current = current->next;
		}
		cout << endl;
	}
};

void simulate_queues(int N)
{
	Queue* queues = new Queue[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 7; j++)
			queues[i].enqueue(j);

	int rear = N - 1;
	int front = 0;
	while (!queues[rear].isEmpty())
	{
		queues[rear].dequeue();
		for (int i = rear; i > front; i--)
		{
			queues[i].enqueue(queues[i - 1].dequeue());
		}

		if (queues[front].isEmpty())
			front++;

		for (int j = rear; j >= front; j--)
		{
			cout << "Ticket Collector: " << endl;
			cout << "Queue " << j << ": ";
			queues[j].print();
		}
		cout << endl;
	}

	cout << "No Person Remaining" << endl;
}

int main()
{
	int N;

	cout << "Enter number of queues: ";
	cin >> N;

	simulate_queues(N);

	return 0;
}