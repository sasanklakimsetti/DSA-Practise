/**************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
Case1: Insertion at beginning

Case2: Insertion at End

Case 3:Insertion at Specific position

Case4: Deletion from beginning

Case5: Deletion from End

Case 6:Deletion from a specific position

Case7: Find the length of a linked list

Case 8: Reverse the Linked list

***************************/

#include <stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
int main ()
{
  int n, a;
  printf ("enter no of elements ");
  scanf ("%d", &n);
  struct node *head = NULL, *temp = NULL;
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a);
      struct node *first = (struct node *) malloc (sizeof (struct node));
      if (head == NULL)
	{
	  first->data = a;
	  first->link = NULL;
	  head = first;
	  temp = first;
	}
      else
	{
	  first->data = a;
	  first->link = NULL;
	  temp->link = first;
	  temp = first;
	}
    }
  struct node *ptr = (struct node *) malloc (sizeof (struct node));
  ptr = head;
  int count = 0;
  while (ptr != NULL)
    {
      printf ("%d\n", ptr->data);
      ptr = ptr->link;
      count++;
    }
  int x, b, z;

  printf
    ("Case1: Insertion at beginning\nCase2: Insertion at End\nCase 3:Insertion at Specific position\nCase4: Deletion from beginning\nCase5: Deletion from End\nCase 6:Deletion from a specific position\nCase7: Find the length of a linked list\nCase 8: Reverse the Linked list");
  scanf ("%d", &x);

  switch (x)
    {
      //insertion at beggining
    case 1:
      {
	printf ("enter a number to insert");
	scanf ("%d", &b);
	struct node *first = (struct node *) malloc (sizeof (struct node));
	first->data = b;
	first->link = head;
	head = first;

	break;
      }
      //insertion at end
    case 2:
      {
	printf ("enter a number to insert");
	scanf ("%d", &b);
	struct node *first = (struct node *) malloc (sizeof (struct node));
	first->data = b;
	first->link = NULL;
	temp->link = first;



	break;
      }
      //inserting at specific position
    case 3:
      {
	printf ("enter a number to insert");
	scanf ("%d", &b);
	int count = 0;
	printf ("enter  position");
	scanf ("%d", &z);
	struct node *p1 = (struct node *) malloc (sizeof (struct node));
	p1 = head;
	struct node *first = (struct node *) malloc (sizeof (struct node));
	struct node *temp;
	while (p1 != NULL)
	  {
	    count++;
	    if (z == 1)
	      {
		first->data = b;
		first->link = head;
		head = first;
		break;
	      }
	    else if (count == z - 1)
	      {
		first->data = b;
		first->link = p1->link;
		p1->link = first;
		break;
	      }
	    p1 = p1->link;
	  }
	break;
      }
      //Deletion at from beggining
    case 4:
      {
	head = head->link;

	break;
      }
      //deletion at end
    case 5:
      {
	int count = 0;
	struct node *p1 = (struct node *) malloc (sizeof (struct node));
	p1 = head;
	struct node *temp;
	while (p1 != NULL)
	  {
	    count++;
	    if (count == n - 1)
	      {
		p1->link = NULL;
		break;
	      }
	    p1 = p1->link;
	  }



	break;
      }
      //deletion at specific position
    case 6:
      {
	printf ("enter  position");
	scanf ("%d", &z);
	struct node *p1 = (struct node *) malloc (sizeof (struct node));
	p1 = head;
	int count = 0;
	while (p1 != NULL)
	  {
	    count++;
	    if (z == 1)
	      {

		head = p1->link;
		break;
	      }
	    else if (count == z - 1)
	      {
		p1->link = p1->link->link;
		break;
	      }
	    p1 = p1->link;
	  }



	break;
      }
      //no of elements
    case 7:
      {
	struct node *p1 = (struct node *) malloc (sizeof (struct node));
	p1 = head;
	int count = 0;
	while (p1 != NULL)
	  {
	    printf ("%d\n", p1->data);
	    count++;
	    p1 = p1->link;

	  }
	printf ("total no of elements are %d\n", count);


	break;
      }
      //reversing
    case 8:
      {
	struct node *prev = NULL;
	struct node *current = head;
	struct node *next = NULL;

	while (current != NULL)
	  {
	    next = current->link;
	    current->link = prev;
	    prev = current;
	    current = next;
	  }

	head = prev;
	break;
      }


    }



  struct node *p = (struct node *) malloc (sizeof (struct node));
  p = head;
  while (p != NULL)
    {
      printf ("%d\n", p->data);
      p = p->link;

    }

  return 0;
}