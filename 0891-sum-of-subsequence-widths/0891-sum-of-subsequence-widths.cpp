class Solution {
public:
    
    int sumSubseqWidths(vector<int>& nums) {
        int  n=nums.size();
            long mod=1e9+7;
        sort(nums.begin(),nums.end());

                //creating a power array to store power which will help us in calculatin of  number of subsets having element as min a ns maximum
        
        vector<long>pow(n);
        pow[0]=1;
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%mod;
        }
        long ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+(pow[i]-pow[n-i-1])*nums[i])%mod;
        }
        return (int)ans;
        
    }
};