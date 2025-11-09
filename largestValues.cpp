class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int s = q.size();
            int levelMax = INT_MIN;  

            for(int i = 0; i < s; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                levelMax = max(levelMax, curr->val); 

                if(curr->left != NULL)
                    q.push(curr->left);

                if(curr->right != NULL)
                    q.push(curr->right);
            }

            ans.push_back(levelMax);  
        }

        return ans;
    }
};
