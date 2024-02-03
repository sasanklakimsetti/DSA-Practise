//OCCURRENCE OF CONSECUTIVE CHARACTERS IN THE STRINGS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string s){
//complete the function here
string ans;
int n = s.size();
for(int i=0;i<n;i++)
{
int j=i,x=0;
while(tolower(s[j]) == tolower(s[i]))
{
j++;
x++;
}
char ch = tolower(s[i]);
ans += to_string(x) + ch;
i=j-1;
}
return ans;
}
