/*Given the binary Tree of and two-node values. Check whether the two-node values are cousins of each other or not.

Example 1:

Input:
      1
    /   \
   2     3
a = 2, b = 3
Output: 0

Example 2:

Input:
       1
     /   \ 
    2     3
   /       \
  5         4 
a = 5, b = 4
Output: 1
Explanation: Here, nodes 5 and 4 are
at the same level and have different
parent nodes. Hence, they both are cousins 

Your Task:
You don't need to read input or print anything. Your task is to complete the function isCousins() that takes the root node of the tree (having all nodes distinct), and two integers 'a' and 'b' as inputs. It returns true if the nodes with given values 'a' and 'b' are Cousins of each other and returns false otherwise. 
Two nodes value are cousins of each other if they are at the same level and have different parents. (The driver code will print 1 if the returned values is true,otherwise 0.)

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000


Note: The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b)
{
//add code here.
queue<Node*>q;
int x=1;
q.push(root);
while(!q.empty())
{
int f=0;
while(x--)
{
if(q.front()->left != NULL)q.push(q.front()->left);
if(q.front()->right != NULL)q.push(q.front()->right);
if(q.front()->data == a || q.front()->data == b)
{
f++;
}
if(q.front()->left != NULL && q.front()->right != NULL)
{
if(q.front()->left->data == a && q.front()->right->data == b)return 0;
if(q.front()->left->data == b && q.front()->right->data == a) return 0;
}
q.front();
q.pop();
}
if(f==2) return 1;
x=q.size();
}
return 0;
}