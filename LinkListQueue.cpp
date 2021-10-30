#include<iostream>
using namespace std;

//Doubly Circular Link List
class List
{
private:
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head;
public:
    List()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    void InsertatHead(int data)
    {
        Node* newNode = new Node;
        if (head == NULL)
        {
            newNode->next = head;
            newNode->prev = head;
            newNode->data = data;
            head = newNode;
        }
        
        newNode->data = data;
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev = newNode;
        head = newNode;
        newNode->prev->next = head;
    }
    void DeleteatTail()
    {
        if (head->next != head)
        {
            Node* temp = head->prev->prev;
            delete head->prev;
            temp->next = head;
            head->prev = temp;
        }
        else
        {
            delete head;
            head = nullptr;
        }

    }
    void makenull()
    {
        while (true)
        {
            if (isEmpty())
            {
                break;
            }
            else
            {
                DeleteatTail();
            }
        }
    }
    void display()
    {
        Node* temp = head;
        cout << "Display\n";
        while (temp->next != head)
        {
           
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
        cout << endl;
    }
};

class QUEUE
{
private:
    List list;
public:
    void Enqueue(int data)
    {
        list.InsertatHead(data);
    }
    void Dequeue()
    {
        if (list.isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        list.DeleteatTail();
    }
    void makeNull()
    {
        list.makenull();
    }
    void Display()
    {
        if (list.isEmpty())
        {
            cout << "Nothing to Display\n";
            return;
        }
        list.display();
    }
};

int main()
{
    int ch, data;
    	QUEUE line;
    	while (true)
    	{
    
    		cout << "1.) Enqueue\n2.) Dequeue\n3.) Display\n4.) Make Null\n5.) Quit\n\nEnter : ";
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
                line.makeNull();
                break;
    		case 5:
    			return 0;
    		default:
    			cout << "Enter valid Input\n";
    			break;
    		}
    	}
}