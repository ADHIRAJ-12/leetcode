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
    
    
    
    bool stoneGame(vector<int>& nums) {
     int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(true,0,n-1,nums,dp)>0;
       
    }
};

//  int n=nums.size(),a=0,b=0;
//         int i=0,j=n-1;
//         while(i<=j){
//             if(nums[i]>nums[j]){
//                 a+=nums[i];
//                 b+=nums[j];
//                 i++;
//                 j--;
//             }
          
//             else{
//                 a+=nums[j];
//                 b+=nums[i];
//                 i++;
//                 j--;
//             }
            
//         }
//         if(a>b)return true;
//         else return false;
            