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
void inorder(TreeNode*root, vector<int>&nodes)
{
    if(root==NULL)
    return;

    inorder(root->left,nodes);
    nodes.push_back(root->val);
    inorder(root->right,nodes);
}
    bool findTarget(TreeNode* root, int k) 
    {
        if(root==NULL)
        return false;

        vector<int>nodes;
        inorder(root,nodes);
        int i=0;
        int j=nodes.size()-1;
        while(i<j)
        {
            int sum=nodes[i]+nodes[j];
            if(sum==k)
            {
                return true;
            }
            else if(sum<k)
            i++;
            else
            j--;
        }
        return false;
    }
};
