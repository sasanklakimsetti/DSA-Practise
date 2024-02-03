//Linked list is a linear data structure
//Node in linked list contains Data and Reference
//Reference contains pointers.
//1st node stores in address called Head and last address will always be null;
//Head always contain the address first node
//Types of linked list: Singly,Doubly,Circular
//2000 -> 10 3000 -> 20 4000 -> 30 NULL;    Singly
//Doubly:  Previous Node's Address Data Next Node's Data
struct node
{
    int data;
    struct node *next;
};    //singly linked list : can be traversed only in single way
//Doubly Linked List :  can be traversed in both directions
/*
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
*/

//Singly Circular Linkked List : The last reference contains the address of first node as well as head;
//Doubly Circular List: 