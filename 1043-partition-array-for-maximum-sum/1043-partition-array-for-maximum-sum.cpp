class Solution {
public:
    
    int f(int ind,vector<int>&nums,int k, vector<int>&dp){
        
        int n=nums.size();
        
        if(dp[ind]!=-1)return dp[ind];
        if(ind==n)return 0;
        int maxi=INT_MIN,ans=INT_MIN,len=0;
        
        for(int j=ind;j<min(ind+k,n);j++){
            
            len++;
            maxi=max(maxi,nums[j]);
            int sum= (len*maxi)+f(j+1,nums,k,dp);
            ans=max(ans,sum);
            
        }
        
        return dp[ind]=ans;
        
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return f(0,arr,k,dp);
        
    }
};