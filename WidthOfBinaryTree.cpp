/*
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
*/


int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int first=0,last=0;
        while(q.size())
        {
            int n=q.size();
            int currmin=q.front().second;
            first=currmin;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front().first;
                int idx=q.front().second;
                q.pop();
                if(temp->left)
                {
                    q.push({temp->left,2*(idx-currmin)+1});
                }
                if(temp->right)
                {
                    q.push({temp->right,2*(idx-currmin)+2});
                }
                if(i==n-1)
                    last=idx;
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }