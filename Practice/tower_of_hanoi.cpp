#include<iostream>
using namespace std;
void towerOfHanoi(int n,char from, char to, char aux)
{
    if(n==0) return;
    else
    {
        towerOfHanoi(n-1,from,aux,to);
        cout<<n<<":"<<from<<" to "<<to<<endl;
        towerOfHanoi(n-1,aux,to,from);
    }
}
int main()
{
    int n=3;
    towerOfHanoi(n,'A','C','B');
}