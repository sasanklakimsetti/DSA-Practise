#include <iostream>
#include <vector>

// Define a structure for a node in the linked list
struct Node {
    int shift;
    Node* next;

    Node(int shift) : shift(shift), next(nullptr) {}
};

// Function to create a new node
Node* createNode(int shift) {
    return new Node(shift);
}

// Function to insert a node at the end of the linked list
void insertNode(Node*& head, int shift) {
    Node* newNode = createNode(shift);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to left-shift the linked list by 'k' shifts
Node* leftShift(Node* head, int k) {
    if (!head || k <= 0) {
        return head;
    }

    int length = 0;
    Node* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    k = k % length; // Handle cases where k is greater than the length of the list

    if (k == 0) {
        return head;
    }

    Node* newHead = head;
    Node* tail = head;

    // Find the new head and tail of the linked list after left-shifting
    for (int i = 1; i < k; i++) {
        tail = tail->next;
    }

    newHead = tail->next;
    tail->next = nullptr;

    // Find the end of the new linked list and connect it to the original head
    current = newHead;
    while (current->next) {
        current = current->next;
    }

    current->next = head;

    return newHead;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->shift << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    Node* schedule = nullptr;

    for (int i = 0; i < N; i++) {
        int shift;
        std::cin >> shift;
        insertNode(schedule, shift);
    }

    int k;
    std::cin >> k;

    std::cout << "Original Schedule: ";
    displayList(schedule);

    schedule = leftShift(schedule, k);

    std::cout << "Modified Schedule: ";
    displayList(schedule);

    return 0;
}