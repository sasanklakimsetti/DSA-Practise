#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a node at the end of a linked list
void insertNode(Node*& head, int value) {
    Node* newNode = new Node(value);
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

// Function to print the elements of a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n;

    Node* list1 = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertNode(list1, value);
    }

    cin >> m;

    Node* list2 = nullptr;
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        insertNode(list2, value);
    }

    // Sort and print both linked lists
    vector<int> sortedList1, sortedList2;
    Node* current1 = list1;
    Node* current2 = list2;

    while (current1) {
        sortedList1.push_back(current1->data);
        current1 = current1->next;
    }
    while (current2) {
        sortedList2.push_back(current2->data);
        current2 = current2->next;
    }

    sort(sortedList1.begin(), sortedList1.end());
    sort(sortedList2.begin(), sortedList2.end());

    cout << "Sorted List 1: ";
    for (int i : sortedList1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Sorted List 2: ";
    for (int i : sortedList2) {
        cout << i << " ";
    }
    cout << endl;

    // Merge the sorted lists, removing duplicate common elements
    vector<int> mergedList;
    merge(sortedList1.begin(), sortedList1.end(), sortedList2.begin(), sortedList2.end(), back_inserter(mergedList));

    cout << "Union with Common Elements Once: ";
    unordered_set<int> seen;
    for (int i : mergedList) {
        if (seen.count(i) == 0) {
            cout << i << " ";
            seen.insert(i);
        }
    }
    cout << endl;

    return 0;
}