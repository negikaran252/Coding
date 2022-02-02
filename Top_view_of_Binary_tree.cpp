vector<int> topView(Node *root)
    {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.empty()==false)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                q.pop();
                Node* curr=p.first;
                int hd=p.second;
                if(mp.find(hd)==mp.end())
                    mp[hd]=curr->data;
                if(curr->left)
                    q.push({curr->left,hd-1});
                if(curr->right)
                    q.push({curr->right,hd+1});
            }
        }
        vector<int> ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }