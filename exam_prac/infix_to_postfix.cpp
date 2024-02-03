#include<stack>
#include<iostream>
using namespace std;
int precedence(char c)
{
    if(c=='^') return 3;
    else if (c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}
void Postfix(string s)
{
    stack<char>st;
    string ns;
    st.push('$');
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ns+=s[i];
        }
        else if (s[i]=='(')
        {
            st.push('(');
        }
        else if (s[i]==')')
        {
            while(st.top()!='$' && st.top()!='(')
            {
                char c=st.top();
                st.pop();
                ns+=c;
                
            }
            if(st.top()=='(') st.pop();
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
int main()
{
    string s;
    cin>>s;
    Postfix(s);
}