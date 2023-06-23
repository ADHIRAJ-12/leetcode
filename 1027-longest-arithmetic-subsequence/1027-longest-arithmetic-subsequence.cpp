class Solution {
public:
    
//     int solve(int index,int diff,vector<int>& nums){
//         if(index<0)return 0;
        
//         int ans=0;
//         for(int j=index-1;j>=0;j--){
//             if(nums[index]-nums[j]==diff){
//                 ans=max(ans,1+solve(j,diff,nums));
//             }
//         }
//         return ans;
//     }
    
    
    
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
          unordered_map<int,int>dp[n+1];

        if(n<=2) return n;
        int ans=0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int cnt=1;
                
                if(dp[j].count(diff)) cnt=dp[j][diff];
                
                dp[i][diff]=1+cnt;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};