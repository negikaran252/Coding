vector<vector<int>> res;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(q.empty()==false)
        {
            TreeNode*curr=q.front().first;
            int hd=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            mp[hd][level].insert(curr->val);
            if(curr->left)
                q.push({curr->left,{hd-1,level+1}});
            if(curr->right)
                q.push({curr->right,{hd+1,level+1}});
        }
        vector<vector<int>> res;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vector<int> temp;
            for(auto q:it->second)
            {
                temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            res.push_back(temp);
            
        }
        return res;