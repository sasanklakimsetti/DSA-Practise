//IMPLEMENTATION OF QUEUES USING queueAYS
#include<iostream>
using namespace std;
#define SIZE 3
int front=0;
int rear=0;
int queue[SIZE];
void enqueue(int value)
{
    if(rear==SIZE)
    {
        cout<<"Queue is Full. Queue Overflow\n";
    }
    else
    {
        queue[rear]=value;
        rear++;
    }
}
void dequeue()
{
    if(rear==front)
    {
        cout<<"Queue is empty. Queue underflow\n";
    }
    else
    {
        cout<<"The deleted element is "<<queue[front]<<endl;
        for(int i=front;i<rear;i++)
        {
            queue[i]=queue[i+1];
        }
        rear--;
    }
}
void display()
{
    if(front == rear)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"The queue is ";
        int i=front;
        while(i!=rear)
        {
            cout<<queue[i]<<" ";
            i++;
        }
        cout<<endl;
    }
}
int main()
{
    int choice,value;
    while(1)
    {
        cout<<"Enter choice: ";cin>>choice;
        switch (choice){
            case 1:
            {
                cout<<"Enter the value: ";
                cin>>value;
                enqueue(value);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
                break;
            }
            default:
            cout<<"Wrong selection";break;
    }
}
return 0;
}



//IF THE SIZE OF QUEUE TO BE GIVEN AS USER INPUT
/*
#include <iostream>
using namespace std;

int front = -1;
int rear = -1;
int* queue; // Pointer to dynamically allocated array

void initializeQueue(int size) {
    queue = new int[size]; // Dynamically allocate memory for the queue
}

void enqueue(int value, int size) {
    if (rear == size - 1) {
        cout << "Queue is Full. Queue Overflow\n";
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (rear == front) {
        cout << "Queue is empty. Queue underflow\n";
    } else {
        cout << "The deleted element is " << queue[front] << endl;
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "The queue is ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value, size;

    cout << "Enter the size of the queue: ";
    cin >> size;
    initializeQueue(size);

    while (1) {
        cout << "\nQueue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                enqueue(value, size);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                delete[] queue; // Free dynamically allocated memory
                cout << "Exiting the program." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
*/