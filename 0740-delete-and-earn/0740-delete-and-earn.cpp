class Solution {
public:
    
     int solve(int ind,vector<int>& dp,vector<int> & nums){
     
     if(ind==0)return nums[ind];
     if(ind<0)return 0;
     
     if(dp[ind]!=-1)return dp[ind];
    
    int take=nums[ind]+solve(ind-2,dp,nums);
    int nottake=0+solve(ind-1,dp,nums);

    return dp[ind]=max(take,nottake);

    }
     
    int deleteAndEarn(vector<int>& nums) {
        
        
        int n=nums.size();
        int maxi = *max_element(nums.begin(),nums.end());

		vector<int>freq(maxi+1,0);
        for(int i = 0 ; i < nums.size(); i++)freq[nums[i]]+=nums[i];
		  
        vector<int>dp(freq.size(),-1);
        return solve(freq.size()-1,dp,freq);

        
    }
};