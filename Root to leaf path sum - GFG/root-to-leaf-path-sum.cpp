//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution
{
    public:
    void sol(Node *root,vector<int> &ans,int sum){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            sum+=root->data;
            ans.push_back(sum);
            // sum=0;
            return ;
        }
        sum+=root->data;
        sol(root->left,ans,sum);
        sol(root->right,ans,sum);
    }
    bool hasPathSum(Node *root, int S) {
    // Your code here
    vector<int>ans;
    // int sum=0;
    sol(root,ans,0);
    for(int i=0;i<ans.size();i++){
        if(ans[i]== S) return true;
    }
    // for(int i=0;i<ans.size();i++){
    //      cout<<ans[i]<<endl;
    // }
    return false;
    
}
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        Solution ob;
        cout << ob.hasPathSum(root, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends