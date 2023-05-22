class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>count;        //counting freq of elements
        for(auto num:nums) count[num]++;
        
        priority_queue<pair<int,int>>pq;
      for(auto& pair: count) pq.emplace(pair.second, pair.first);        
        vector<int>ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};

//emplace pushes acc to the priority