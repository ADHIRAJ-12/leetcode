class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        
        int ans=0;
        for(auto i:mp){
            if(mp.find(i.first+1)!=mp.end()){
                ans= max(ans,mp[i.first]+mp[i.first+1]);
            }
        } 
        
        return ans;
        
    }
};