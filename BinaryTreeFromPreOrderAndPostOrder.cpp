map<int,int> mp;
    int postindex=0;
    TreeNode* prev=NULL;
    TreeNode* help(vector<int>& preorder, vector<int>& postorder,int ps,int pend,int pos,int poe) {
        if(ps>pend)
            return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        if(ps==pend)
        {
            return root;
        }
        int index=mp[preorder[ps+1]];
        int nums=index-pos+1;
        root->left=help(preorder,postorder,ps+1,ps+nums,pos,index);
        root->right=help(preorder,postorder,ps+nums+1,pend,index+1,poe-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++)
        {
            mp[postorder[i]]=i;
        }
        return help(preorder,postorder,0,n-1,0,n-1);
    }
};