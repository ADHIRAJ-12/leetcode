class Solution {
public:
    int maxCoins(vector<int>& piles) {
        priority_queue<int>pq;
        for(auto i:piles)pq.push(i);
        int ans=0;
        int n=piles.size()/3;
        while(n--){
            pq.pop();
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
        }
};