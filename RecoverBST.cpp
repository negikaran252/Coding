/* Two nodes in BST are swapped*/

TreeNode* first=NULL,*second=NULL,*prev=NULL;
    void help(TreeNode* root)
    {
        if(root==NULL)
            return;
        help(root->left);
        if(prev!=NULL && root->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
            }
            second=root;
        }
        prev=root;
        help(root->right);
    }
    void recoverTree(TreeNode* root) {
        help(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        
    }