class Solution {
public:
    //byspace  optimisation dp

    int spaceOptp(vector<int>& cost,int n){
        
        int prev2=cost[0];
        int prev1=cost[1];
        
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
        return spaceOptp(cost,n);

 
    }
}; 


                              //  by tabulation dp

//  int tabulation(vector<int>& cost,int n){
//         vector<int> dp(n+1);
        
//         dp[0]=cost[0];
//         dp[1]=cost[1];
        
//         for(int i=2;i<n;i++){
//             dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
//         }
//         return min(dp[n-1],dp[n-2]);
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//        int n=cost.size();
//         return tabulation(cost,n);

 
//     }




              // by top bottom dp


//  int solve(vector<int>& cost,int n,vector<int> &dp){
//         //base
//         if(n==0) return cost[0];
//         if(n==1) return cost[1];
        
//         if(dp[n]!=-1) return dp[n];
        
//         dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
//         return dp[n];
        
//     }
                    //main(){
 //        int n=cost.size();
 //        vector<int>dp(n+1,-1);
 //        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
 //        return ans;
// }





                   //        brute force


//  for(int i=2;i<cost.size();i++)
//         {
//             cost[i]+=min(cost[i-1],cost[i-2]);
//         }
//         return min(cost[cost.size()-1],cost[cost.size()-2]);

// see the last stair n either you will be coming from n-1 or from n-2 th stair , so return the stair which provide the minimum cost from the either of the two. 
