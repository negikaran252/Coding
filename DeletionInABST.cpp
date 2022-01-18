TreeNode* getSuccessor(TreeNode* curr)
    {
        while(curr && curr->left)
        {
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        if(root->val<key)
            root->right=deleteNode(root->right,key);
        else if(root->val>key)
            root->left=deleteNode(root->left,key);
        else
        {
            if(root->left==NULL)
            {
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            else if(root->right==NULL)
            {
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
            else
            {
                TreeNode* succ=getSuccessor(root->right);
                root->val=succ->val;
                root->right=deleteNode(root->right,succ->val);
            }
        }
         return root;
    }
};