/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    private:
    stack<TreeNode *>st;
    public:
    BSTIterator(TreeNode* root) {
        // we will push all left nodes into the stack
        pushAll(root);
    }
    
    int next() {
        TreeNode *node=st.top();
        st.pop();
        if(node->right)
            pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return st.empty()==false;
    }
    private:
    void pushAll(TreeNode *root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */