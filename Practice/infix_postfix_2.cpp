#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#define MAX 100
using namespace std;
string ns;
int precedence(char c)
{
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}
void infixToPostfix(string s)
{
    stack<char>st;
    st.push('$');
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ns+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push('(');
        }
        else if(s[i]==')')
        {
            while(st.top()!='$'&&st.top()!='(')
            {
                char c=st.top();
                st.pop();
                ns+=c;
            }
            if(st.top()=='(') 
            {
                st.pop();
            }
        }
        else
        {
            while(st.top()!='$'&&precedence(s[i])<=precedence(st.top()))
            {
                char c=st.top();
                st.pop();
                ns+=c;
            }
            st.push(s[i]);
        }
    }
    while(st.top()!='$')
    {
        char c=st.top();
        st.pop();
        ns+=c;
    }
    cout<<ns<<endl;
}
int PostEvaluation(string ns)
{
    int a,b;
    stack<char>post;
    int m=ns.length();
    for(int i=0;i<m;i++)
    {
        if(ns[i]>='0'&&ns[i]<='9')
        {
            post.push(ns[i]);
        }
        else
        {
            a=post.pop();
            b=post.pop();
            if(ns[i]=='+') post.push(b+a);
            else if(ns[i]=='-') post.push(b-a);
            else if(ns[i]=='*') post.push(b*a);
            else if(ns[i]=='/') post.push(b/a);
            else if(ns[i]=='^') post.push(pow(b,a));
        }
    }
    return post.top();
}
int main()
{
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;
    infixToPostfix(infix);
    PostEvaluation(ns);

}