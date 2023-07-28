class Solution {
public:
    
    
int solve(bool turn,int l ,int r, vector<int>& nums,vector<vector<int>>&dp ){
        
        if(l>r)return 0;
        if(l==r)return nums[l];
        
        if(dp[l][r]!=-1)return dp[l][r];
        
        if(turn) dp[l][r]=max((nums[l]+solve(!turn,l+1,r,nums,dp)),(nums[r]+solve(!turn,l,r-1,nums,dp)));    
        else  dp[l][r]=min((-nums[l]+solve(!turn,l+1,r,nums,dp)),(-nums[r]+solve(!turn,l,r-1,nums,dp)));    
        
        return dp[l][r];
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n==1 && nums[0]==0)return true;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(true,0,n-1,nums,dp)>=0;
    }
};