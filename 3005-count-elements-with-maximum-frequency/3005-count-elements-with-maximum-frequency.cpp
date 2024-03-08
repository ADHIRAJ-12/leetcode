class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)m[nums[i]]++;
        
        int maxi=0,ans=0;
        for(auto i:m)maxi=max(maxi,i.second);
        
        for(auto i:m){
            if(i.second==maxi)ans+=i.second;
        }
        return ans;
        
    }
};