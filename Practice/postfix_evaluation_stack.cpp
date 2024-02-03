//Evaluation of Postfix expression using stacks
/*Algorithm:
Scan the symbols of the given postfix expression from left to right and for each symbol,do the following:
1.If symbol is an operand---> Push it on the stack
2.If symbol is an operator---> Pop two symbols out of the stack and apply the operatir on these symbols and push the result on the stack.
3.After scanning all the symbols of the postfix expression, pop the remaining symbol out of the stack and print it on the screen. The remaining symbol is the result obtained after evaluating the postfix expression.Let's consider postfix expression:
7 5 3 * 5 1 ^ / + 3 2 - /

Scan all symbols from left to right
Steps:
1.Push 7 onto the stack
2.Push 5 onto the stack
3.Push 3 onto the stack
4.Pop previous two operands i.e. 3,5 and apply * on those two operands i.e. perform multiplication ---> a=3,b=5 result = b*a = 5*3= 15
5.Push 15 on the stack
6.Push 5 on the stack
7.Push 1 on the stack
8.Pop 1,5 out the stack and perform ^ i.e. a=1,b=5 result = b^a = 5^1=5
9.Push 5 onto the stack
10.Pop 5,15 and perform / i.e. a=5,b=15 result = b/a = 15/5 = 3
11.Push 3 onto the stack
12.Pop 3,7 and perform + i.e. a=3,b=7 result = b+a = 7+3 = 10
13.Push 10 onto the stack
14.Push 3 onto the stack 
15.Push 2 onto the stack
16.Pop 2,3 and perform - i.e. a=2,b=3 result = b-a = 3-2 = 1
17.Push 1 onto the stack 
18.Pop 1,10 and perform + i.e. a=1,b=10 result=b+a = 10+1 = b+a = 11
19.Push 11 onto the stack
20.Pop 11 out of the stack and print on the screen as no symbols present in the expression

*/

#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<stdlib.h>
#define MAX 100
int stac[MAX]; //return type changed from char to int
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
int pop() //return type changed from char to int
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
int post_eval()
{
    int i,a,b;
    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]>='0'&&postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+':
                push(b+a);
                break;
                case '-':
                push(b-a);
                break;
                case '*':
                push(b*a);
                break;
                case '/':
                push(b/a);
                break;
                case '^':
                push(pow(b,a));
                break;
            }
        }
    }
    return pop();
}
int main()
{
    top=-1;
    cout<<"Enter the infix expression: ";
    cin.getline(infix,MAX); //gets--> get string function
    inToPost();
    print();
    cout<<"The value of the given expression is "<<post_eval();
    return 0;
}


/*Drawbacks:

this code only works for single digit operands

for simplicity, we have considered that the associativity of all operators is left to right, but in reality, this is not the case


*/