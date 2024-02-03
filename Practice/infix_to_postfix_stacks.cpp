//Conversion of Infix expression to Postfix expressions using Stacks

/* How to convert:
Scan the symbols of the expressions from left to right and for each symbol, do the following:
a. If symbol is operand---> Print the symbol onto the screen.
b. If symbol is left paranthesis---> Push it on the stack/
c. If symbol is right paranthesis---> Pop all the operators from the stack upto the first left paranthesis and print them on the screen. Discard the left and right operands.
d. If symbol is an operator ---> *If the precedence of the operators in the stack are greater than or equal to the current operator, then pop the operators out of the stack and print them onto the screen, and push the current operator onto the stack.    *else, push the current operator onto the stack
*/

/* Let's consider an infix expression 
7 + 5 * 3 / 5 ^ 1 + (3 - 2)
Step-1: As 7 is operand, print it on screen
Step-2: As '+' is operator, push it into the stack
Step-3: As 5 is operand, print it on the screen
Step-4: As '*' is an operator, push it onto the stack.
Step-5: As 3 is operand, print it on the screen
Step-6: As '/' is an operator and its precedence is equal to '*', pop out '*' out of the stack first and check for the other operators(if present), if the precedence is greater than or equal to the current operator, pop out and print it on the screen, else push the current operator onto the stack. As '+' precedence is lower than the '/', push '/' onto the stack 
Step-7: As 5 is operand, print it on the screen
Step-8: '^' precedence is higher than the '/'&'+',push it onto the stack.
Step-9: As 1 is operand, print it on the screen
Step-10: As '+' precedence is less than '^','/' pop them out and print them on the screen and as both are '+', pop '+' which is present in the stack and print it on the screen and push the current '+' into the stack.
Step-11: As '(' occurs, push on the stack
Step-12: Print 3 on the screen
Step-13: '(' has least precedence among all, so push '-' into the stack 
Step-14: Print 2 on the screen
Step-15: As ')' occurs, pop all operators upto the first '(', so pop '-' from the stack and print on screen, later pop the left paranthesis and don't print on the screen and pop '+' from the stack and print it on the screen.

So, the postfix expression will be 
7 5 3 * 5 1 ^ / + 3 2 - +
*/

/* Another example:
8*(5^4+2)-6^2/(9*3)

Applying the algorithm on the given infix expression:
 1.Print 8 on the screen
 2.Push * into stack
 3.Push '(' into stack
 4.Print 5 on screen
 5.Push '^' into stack
 6.print 4 on screen
 7.Pop '^' and print on screen and push '+' into stack
 8.Print 2 on screen
 9.Pop '+' and print on screen and pop '(' from stack and don't print on stack
 after this operation, '*' will be present in the stack
 10.Pop '*' and print on screen and push '-' into stack
 11. Print 6 on screen
 12.Push '^' into stack
 13.Print 2 on screen
 14.Pop '^' and print on screen and push '/' into stack
 15.push '(' into stack 
 16.print 9 on screen
 17.push '*' into stack
 18.print 3 on screen
 19.Pop '*' and print on screen and pop '(' from stack and don't print on screen
 after this, pop '/' followed by '-' from stack and print on screen

 The postfix expression will be
 8 5 4 ^ 2 + * 6 2 ^ 9 3 * / 
 */


#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<stdlib.h>
#define MAX 100
char stac[MAX]; //used character so that we could store symbols
char infix[MAX],postfix[MAX]; //arrays to store infix and postfix symbols
int top=-1; //index of stack
using namespace std;
//Function to change the infix expression to postfix expression
int precedence(char symbol)
{
    switch(symbol)
    {
        //Higher value means greater precedence
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
int isEmpty()
{
    return top==-1;
}
bool isFull()
{
    return top==MAX-1;
}
void push(char value)
{
    if(!isFull())
    {
        stac[++top]=value;
    }
    else
    {
        cout<<"Stack is full. Can't push";
    }
}
char pop()
{
    char c;
    if(top==-1)
    {
        cout<<endl<<"Stack underflow."<<endl;
        exit(1);
    }
    c=stac[top];
    top=top-1;
    return c;
}
int space(char c)
{
    //if symbol is a blankspace or tab
    if(c==' '||c=='\t')
    return 1;
    else
    return 0;
}
void inToPost()
{
    //Create a for loop which will run until all the symbols of the expression are read.
    int i;
    int j=0;
    int n=strlen(infix);
    char symbol,next;
    for(i=0;i<n;i++) //string produces '\0' at the end of array which includes the end of string. using i<strlen(infix) will read the symbol before the end of string
    {
        if(!space(symbol)) //if symbol is not a whitespace
        {
            symbol=infix[i];
            switch(symbol)
            {
                case '(':
                push(symbol);
                break;
                case ')': //pop all the operators from stack upto the first left parantheis and store the operators in the postfix array
                while((next=pop())!='(') //this while loop will also discard the left paranthesis
                {
                    postfix[j++]=next;
                }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                while(!isEmpty()&&precedence(stac[top])>=precedence(symbol))
                {
                    postfix[j++]=pop();
                }
                push(symbol);
                    break;
                default: //if symbol is an operand push it into the postfix array.
                postfix[j++]=symbol;
                break;
            }
        }
    }
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
//we are pushing them into the postfix stack instead of printing on the screen so that we could use it for postfix evaluation
//Same operations according to the algorithm but instead of printing we are storing it in the stack
void print()
{
    int i=0;
    cout<<endl<<"The equivalent postfix expression is: ";
    while(postfix[i])
    {
        cout<<postfix[i++];
    }
    cout<<endl;
}
int main()
{
    top=-1;
    cout<<"Enter the infix expression: ";
    cin.getline(infix,MAX); //gets--> get string function
    inToPost();
    print();
    return 0;
}