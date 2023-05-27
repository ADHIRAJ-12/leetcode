class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(n,"");

        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)pq.push({score[i],i});
        
    int idx;
     if(!pq.empty())
     {
         idx = pq.top().second;
         ans[idx] = "Gold Medal";
         pq.pop();
     }
     if(!pq.empty())
     {
         idx = pq.top().second;
         ans[idx] = "Silver Medal";
         pq.pop();
     }
     if(!pq.empty())
     {
         idx = pq.top().second;
         ans[idx] = "Bronze Medal";
         pq.pop();
     }
        
    int x = 4;
     while(!pq.empty())
     {
         idx = pq.top().second;
         ans[idx] = to_string(x);
         pq.pop();
         x++;
     }
    return ans;
        
    }
};