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
class Solution {
public:
    int len(TreeNode *root){
        if(root==NULL) return 0;

        return 1+max(len(root->left),len(root->right));
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left=len(root->left);
        int right=len(root->right);
        
        if(left >right)
            return lcaDeepestLeaves(root->left);
        else if(right>left)
            return lcaDeepestLeaves(root->right);
        else
            return root;
    }
};