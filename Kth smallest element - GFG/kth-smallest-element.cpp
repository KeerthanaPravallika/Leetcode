 int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int i;
        
        priority_queue<int , vector<int>,greater<int>> pq;
        
        for(i=l;i<r+1;i++)
            pq.push(arr[i]);
        
        int k_small_num,count=1;
        while(!pq.empty())
        {
            if(count == k)
            {
                k_small_num = pq.top();
                break;
            }
            count++;
            pq.pop();
        }
        return k_small_num;
        
    }
