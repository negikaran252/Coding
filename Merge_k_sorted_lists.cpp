struct mycmp
    {
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
            return a.first>b.first;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,ListNode*> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> pq;
        ListNode* ans=NULL,*pointer=NULL;
        int k=lists.size();
        for(int i=0;i<k;i++)
        {
            if(lists[i]!=NULL)
            {
                mp[i]=lists[i];
                pq.push({lists[i]->val,i});    
            }
        }
        while(pq.empty()==false)
        {
            int temp=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            ListNode* curr=new ListNode(temp);
            if(ans==NULL)
            {
                pointer=curr;
                ans=curr;
            }
            else
            {
                pointer->next=curr;
                pointer=pointer->next;
            }
            ListNode* node=mp[idx];
            if(node!=NULL && node->next!=NULL)
                mp[idx]=node->next;
            if(node && node->next!=NULL)
            {
                pq.push({node->next->val,idx});
            }
        }
        return ans;
        
    }