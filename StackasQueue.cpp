#include<iostream>
using namespace std;
//Program where Stack is acting as QUEUE

//Node Struct
struct Node
{
	int data;
	Node* next;
};
//class for Stack
class Stack
{
private:
	class List
	{
	public:
		Node* head;
		List()
		{
			head = nullptr;
		}
	};
	List list;
public:
	Stack() //Constructor
	{
		list.head = NULL;
	}
	void Push(int data)
	{
		
		Node* newNode = new Node;
		newNode->next = list.head;
		newNode->data = data;
		list.head = newNode;
	}
	int Pop()
	{
		if (list.head->next == NULL)
		{
			int temp = list.head->data;
			delete  list.head;
			list.head = NULL;
			return temp;
		}
		Node* temp = list.head->next;
		int temp2 = list.head->data;
		delete list.head;
		list.head = temp;
		return temp2;
	}
	bool isEmpty()
	{
		return (list.head == NULL);
	}
	void display()
	{
		Node* temp;
		temp = list.head;
		int i = 0;
		while (temp != NULL)
		{
			cout << "Element "<<temp->data << endl;
			temp = temp->next;
			i++;
		}
	}
};


//Queue Class
class QUEUE
{
private:
	Stack primary;
	Stack secondary;
public:
	void Enqueue(int data)
	{
		if (primary.isEmpty())
		{
			primary.Push(data);
			return;
		}
		send();
		primary.Push(data);
		retrieve();
	}
	void Dequeue()
	{
		if (primary.isEmpty())
		{
			cout << "Underflow\n";
			return;
		}
		cout << "Popped Element : " << primary.Pop() << endl;
	}
	void Display()
	{
		cout << "Display\n";
		primary.display();
	}
	void send()
	{
		if (primary.isEmpty())
		{
			return;
		}
		int temp = primary.Pop();
		secondary.Push(temp);
		send();
	}
	void retrieve()
	{
		if (secondary.isEmpty())
			return;
		int temp = secondary.Pop();
		primary.Push(temp);
		retrieve();
	}
	~QUEUE() //Destructor
	{
		cout << "Deleted Secondary and Primary Stack\n";
		while (secondary.isEmpty())
		{
			secondary.Pop();
		}
		while (primary.isEmpty())
		{
			primary.Pop();
		}
	}
};





int main()
{
	int ch,data;
	QUEUE line;
	while (true)
	{

		cout << "1.) Enqueue\n2.) Dequeue\n3.) Display\n4.) Quit\n\nEnter : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter data : ";
			cin >> data;
			line.Enqueue(data);
			break;
		case 2:
			line.Dequeue();
			break;
		case 3:
			line.Display();
			break;
		case 4:
			return 0;
		default:
			cout << "Enter valid Input\n";
			break;
		}
	}
}