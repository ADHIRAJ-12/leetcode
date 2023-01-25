class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        
        unordered_map<int,int>m;
        m[0]=1;
        int sum=0, count=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(m[sum-goal])
                count+=m[sum-goal];
            m[sum]++;
        }
        return count;
    }
};