#include<iostream>
using namespace std;

class QUEUE
{
private:
    int* arr;
    int front;
    int rear;
    int size;
public:
    QUEUE()
    {
        cout << "Enter Size of QUEUE\n";
        cin >> size;

        arr = new int[size];
        front = 0;
        rear = -1;
    }
    bool isFull()
    {
        if (rear == -1)
            return false;
        if ((rear + 1) % size == 0 && front == 0|| rear == front - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (front == 0 && rear == -1)
            return true;
        else
            return false;
    }
    void Enqueue(int data)
    {
        if (isFull())
        {
            cout << "OverFlow\n";
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        if (rear == front)
        {
            rear = -1;
            front = 0;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    void makeNull()
    {
        front = 0;
        rear = -1;
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "Nothing to Display\n";
            return;
        }

        int temp = front;
        while(temp != rear)
        {
            cout << arr[temp] << " ";
            temp = (temp + 1) % size;
        }
        cout << arr[rear];
        cout << endl;
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