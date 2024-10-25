#include<iostream>
using namespace std;

class Stack
{
private:
	struct Node
	{
		string data;
		Node* next;
	};
	Node* top;

public:
	Stack()
	{
		top = NULL;
	}

	// Adds an element at top of the stack
	void add(string _data)
	{
		// If the stack is empty
		if (top == NULL)
		{
			Node* newNode = new Node;
			newNode->data = _data;
			newNode->next = NULL;
			top = newNode;
			return;
		}

		Node* newNode = new Node;
		newNode->data = _data;
		newNode->next = top;
		top = newNode;
	}

	// Returns if the stack is empty
	bool isEmpty()
	{
		return top == NULL;
	}

	// Removes an element from the top of stack
	string pop()
	{
		if (isEmpty())
			return "";
		
		Node* temp = top;
		string data = top->data;
		top = top->next;
		delete temp;
		return data;
	}

	// Returns the top element from the stack
	string peek()
	{
		if (isEmpty())
			return "";

		return top->data;
	}

	// Prints the elements of the stack
	void print()
	{
		Node* current = top;

		while (current)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

bool isPunctuation(char c)
{
	string puncs = ".,!'(){}[];:";

	for (int i = 0; i < puncs.length(); i++)
		if (c == puncs[i])
			return true;
	return false;
}

string getWord(string str, int &idx)
{
	string word = "";

	for (idx; idx < str.length(); idx++)
	{
		if (str[idx] == ' ')
			return word;
		if (!isPunctuation(str[idx]))
			word += str[idx];
		else
		{
			return word;
		}
	}

	return word;
}

Stack encode(string message)
{
	Stack reversedString;

	int wordNo = 0;
	for (int i = 0; i < message.length(); i++)
	{
		string word = getWord(message, i);
		if (wordNo == 0)
			if (word[0] >= 'A' && word[0] <= 'Z')
				word[0] += 32;

		if (i >= message.length())
			if (word[0] >= 'a' && word[0] <= 'z')
				word[0] -= 32;

		reversedString.add(word);
	}

	return reversedString;
}

int main()
{
	Stack encoded = encode("Hey!! How Are You... I am f{ne}");

	encoded.print();

	return 0;
}