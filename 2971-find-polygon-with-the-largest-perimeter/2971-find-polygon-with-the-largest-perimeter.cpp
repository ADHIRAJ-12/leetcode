class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<3)return -1;
        vector<long long>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+nums[i];
        
        //prefix vector ready
        long long ans=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<pre[i-1])ans=max(ans*1LL,pre[i]);
        }
        
        return ans;
        
        
    }
};