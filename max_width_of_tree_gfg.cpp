/*Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes at any level.
For example, the maximum width of the following tree is 4 as there are 4 nodes at the 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Example 1:

Input:
       1
     /    \
    2      3
Output: 2
On the first level there is only
one node 1
On the second level there are
two nodes 2, 3 clearly it is the 
maximum number of nodes at any level

Example 2:

Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2
There is one node on level 1(10)
There is two node on level 2(20, 30)
There is two node on level 3(40, 60)
Hence the answer is 2

Your Task:
You don't have to read any input. Complete the function getMaxWidth() that takes the node as a parameter and returns the maximum width. The driver code does the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Width of the tree).

Constraints:
1 <= Number of Nodes<= 10^5
0 <= nodes values <= 10^5*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        int maximum =INT_MIN;
queue<Node*> q;
int x=1;
q.push(root);
while(!q.empty()){
x=q.size();
maximum = max(maximum,x);
while(x--){
if(q.front()->left)q.push(q.front()->left);
if(q.front()->right)q.push(q.front()->right);
q.pop();
}

}
return maximum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);

        Solution ob;
        cout << ob.getMaxWidth(root) << endl;
    }
    return 0;
}

// } Driver Code Ends