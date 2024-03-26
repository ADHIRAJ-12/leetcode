class Solution {
public:
//     int solve(int ind,int prev,vector<int>&arr,int n,vector<vector<int>>&dp){

//      if(ind==n)return 0;
     
//      if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

//      int nottake=solve(ind+1,prev,arr,n,dp);
//      int take=0;
//      if(prev==-1||arr[ind]>arr[prev])take=1+solve(ind+1,ind,arr,n,dp);

//      return dp[ind][prev+1]=  max(take,nottake);

//  }


//     int lengthOfLIS(vector<int>& arr) {
//         int n=arr.size();
//          // vector<vector<int>>dp(n,vector<int>(n+1,-1));
//          // return solve(0,-1,nums,n,dp);   
//             vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
//             for(int ind=n-1;ind>=0;ind--){
//                 for(int prev=ind-1;prev>=-1;prev--){
//                         int nottake=dp[ind+1][prev+1];
//                         int take=0;
//                       if(prev==-1||arr[ind]>arr[prev])take=1+dp[ind+1][ind+1];
//                         dp[ind][prev+1]=max(take,nottake);
//                 }
//             }
//                      return dp[0][0];
        
//     }
    
//         int lengthOfLIS(vector<int>& arr) {
//         int n=arr.size();
//          // vector<vector<int>>dp(n,vector<int>(n+1,-1));  
//             vector<int>prev1(n+1,0);
//             vector<int>curr(n+1,0);
        
//             for(int ind=n-1;ind>=0;ind--){
//                 for(int prev=ind-1;prev>=-1;prev--){
//                         int nottake=curr[prev+1];
//                         int take=0;
//                         if(prev==-1||arr[ind]>arr[prev])take=1+curr[ind+1];
//                         prev1[prev+1]=max(take,nottake);
//                 }
//                 curr=prev1;
//             }
//                      return curr[0];
        
//     }
    
//      int lengthOfLIS(vector<int>& arr) {
        
//          int n=arr.size();
//          int index=1;
         
//          //vector storing -> len of lis til index i
//          vector<int>dp(n,1),hash(n);
//          int maxi=1;
//          for(int i=1;i<n;i++){
//              hash[i]=i;
//              for(int j=0;j<i;j++)
//              {
//                      if(arr[j]<arr[i]){
//                         dp[i]=max(dp[i],1+dp[j]);
//                         hash[i]=j;
                         
//                      }
                 
//              }
//              if(dp[i]>maxi){
//                  maxi=dp[i];
//                 index=i;
//              }
//          }
         
         
//          vector<int>lis;
//          list.push_back(arr[index]);
         
//          while(has[index]!=index){
//              index=hash[index]
//              lis.push_back(arr[index]);
//          }
         
//          reverse(lis.begin(),lis.end());
//          //return lis
         
//            return maxi;
//     }
    
    
    int lengthOfLIS(vector<int>& arr) {
        
         int n=arr.size();
         vector<int>temp;
         temp.push_back(arr[0]);
        
        for(int i=1;i<n;i++){
            if(arr[i]>temp.back())temp.push_back(arr[i]);
            else{
                int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[ind]=arr[i];
            }
        }
        return temp.size();
        
    }
    
};