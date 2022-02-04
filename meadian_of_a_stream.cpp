priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxpq.push(num);
        minpq.push(maxpq.top());
        maxpq.pop();
        if(minpq.size()>maxpq.size())
        {
            maxpq.push(minpq.top());
            minpq.pop();
        }  
    }
    
    double findMedian() {
        double ans;
        if(minpq.size()==maxpq.size())
        {
            ans=(maxpq.top()+minpq.top())/2.0;
            return ans;
        }
        return maxpq.top();
    }