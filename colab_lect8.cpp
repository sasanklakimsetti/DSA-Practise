#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertNode(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted" << endl;
    }

    void displayListReverse() {
        displayListReverseRecursive(head);
    }

    void displayListReverseRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }
        displayListReverseRecursive(current->next);
        cout << current->data << " ";
    }

    void clearList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList linkedList;

    int data;
    int choice;

    cin >> data;
    linkedList.insertNode(data);

    while (true) {
        cin >> choice;

        if (choice == 0) {
            cin >> data;
            linkedList.insertNode(data);
        } else if (choice == 1) {
            break;
        }
    }

    cout << "Linked list (in reverse order): ";
    linkedList.displayListReverse();
    cout << endl;
    cout << "Node ended" << endl;

    linkedList.clearList(); // Clean up memory

    return 0;
}