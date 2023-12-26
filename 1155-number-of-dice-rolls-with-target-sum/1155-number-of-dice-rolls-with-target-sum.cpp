class Solution {
public:
 #define MOD 1000000007
    
//    int solve(int dice,int faces,int target){
        
//         //base
//         if(target<0 || (dice==0&&target!=0)|| (target==0&&dice!=0)) return 0;
        
//         if(dice==0&&target==0) return 1;
        
//         int ans=0;
//         for(int i=1;i<=faces;i++){
//             ans+=solve(dice-1,faces,target-i);
//         }
//         return ans;
//     }
    
    
    
    
    
    
    
//        int solveMem(int dice,int faces,int target,vector<vector<int>> &dp){
        
//         //base
//         if(target<0 || (dice==0&&target!=0)|| (target==0&&dice!=0)) return 0;
        
//         if(dice==0&&target==0) return 1;
           
//            if(dp[dice][target]!=-1) return dp[dice][target];
        
//         int ans=0;
//         for(int i=1;i<=faces;i++){
//             ans=(ans % MOD+solveMem(dice-1,faces,target-i,dp) % MOD) % MOD;
//         }
//         return dp[dice][target]=ans;
//     }
    
    
    
    
    
//     int solveTab(int d,int f,int t){
//         vector<vector<int>>dp(d+1,vector(t+1,0));
        
//         dp[0][0]=1;
        
//         for(int dice=1;dice<=d;dice++){
//             for(int target=1;target<=t;target++){
                
//         int ans=0;
//         for(int i=1;i<=f;i++){
//             if(target-i>=0)
//             ans=(ans % MOD+(dp[dice-1][target-i]) % MOD) % MOD;
//         }
//          dp[dice][target]=ans;
                
//             }
//         }
//         return dp[d][t];
//     }
    
    
    
    
    
        int solveSpace(int d,int f,int t){
    vector<int> prev(t+1,0);
    vector<int> curr(t+1,0);

        prev[0]=1;
        
        for(int dice=1;dice<=d;dice++){
            for(int target=1;target<=t;target++){
                
        int ans=0;
        for(int i=1;i<=f;i++){
            if(target-i>=0)
            ans=(ans % MOD+(prev[target-i]) % MOD) % MOD;
        }
         curr[target]=ans;
                
            }
            prev =curr;
        }
        return prev[t];
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>>dp(n+1,vector(target+1,-1));
        // return solveMem(n,k,target,dp);
        
        // return solveTab(n,k,target);
        
         return solveSpace(n,k,target);
        
    }
};