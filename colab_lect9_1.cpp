#include <iostream>

using namespace std;

// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node after a specific node in a linked list
void insertAfter(Node* prevNode, int value) {
    if (!prevNode) {
        cout << "Error: Previous node is null." << endl;
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to print the elements of a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    // Take input for the linked list
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (!head || value < head->data) {
            // Insert at the beginning if the list is empty or value is less than the first element
            insertAtBeginning(head, value);
        } else {
            // Find the correct position to insert the value
            Node* current = head;
            while (current->next && current->next->data < value) {
                current = current->next;
            }
            // Insert after current
            insertAfter(current, value);
        }
    }

    // Take input for the new element
    int newValue;
    cin >> newValue;

    // Determine where the new element should be inserted
    if (!head || newValue < head->data) {
        // Insert at the beginning if the list is empty or newValue is less than the first element
        insertAtBeginning(head, newValue);
    } else {
        // Find the correct position to insert the newValue
        Node* current = head;
        while (current->next && current->next->data < newValue) {
            current = current->next;
        }
        // Insert after current
        insertAfter(current, newValue);
    }

    // Print the updated linked list
    printList(head);

    return 0;
}