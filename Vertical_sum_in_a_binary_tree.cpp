vector <int> verticalSum(Node *root) {
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.empty()==false)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node* curr=q.front().first;
                int hd=q.front().second;
                q.pop();
                mp[hd]+=curr->data;
                if(curr->left)
                    q.push({curr->left,hd-1});
                if(curr->right)
                    q.push({curr->right,hd+1});
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }