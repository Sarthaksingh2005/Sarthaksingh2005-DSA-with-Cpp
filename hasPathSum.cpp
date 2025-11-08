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

    bool hasPathSum(TreeNode* root, int ts) 
    {
        if(root==NULL)
        return false;
        
        // leaf node
        if(root->left==NULL&&root->right==NULL)
        return (ts==root->val);

        int nts=ts-root->val;
        return hasPathSum(root->left,nts)||hasPathSum(root->right,nts);       
    }
};
