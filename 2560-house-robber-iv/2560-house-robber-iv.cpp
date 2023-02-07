class Solution {
public:
    // int solve(int ind,vector<int> & nums,int k,vector<vector<int>> &dp){
     
//      if(k==0)return 0;
//      if(ind>=nums.size())return INT_MAX;

//         if(dp[ind][k]!=-1)return dp[ind][k];
         
//         int take = max(nums[ind],solve(ind+2,nums,k-1,dp));
//         int nottake= solve(ind+1,nums,k,dp);       
        
//         return dp[ind][k]=min(take,nottake);
//     }
    
        bool solve(vector<int> nums,int k,int mid,int n){
            int i=0;
            while(i<n){
                if(nums[i]<=mid){
                    k--;
                    i+=2;
                }
                else i++;
                if(k==0)return true;
                
            }
            return k==0;
        }
        
        
    int minCapability(vector<int>& nums, int k) {
     
        int n=nums.size();
        int s=0,e=1e9+1;
        while(s<e){
            int mid=(s+e)/2;
            if(solve(nums,k,mid,n))e=mid;
            else s=mid+1;
        }
        return s;
        
        
    }
};