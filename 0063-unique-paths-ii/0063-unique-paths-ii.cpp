class Solution {
public:
    
    
//     int solve(int row,int col,vector<vector<int>>& arr, vector<vector<int>>&dp){
        
//     //base case
//         if(row==0 && col==0 && arr[row][col]!=1)return 1;
//         if(row<0 || col<0)return 0;
//         if(arr[row][col]==1)return 0;
        
//         if(dp[row][col]!=-1)return dp[row][col];
        
//         int top=solve(row-1,col,arr,dp);
//         int left=solve(row,col-1,arr,dp);

//         return dp[row][col]= top+left;
        
//     }
    
    
    
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        
        int m=arr.size(),n=arr[0].size();
        vector<int>dp(n,0);
    
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
              
               if(arr[i][j]==1)temp[j]=0;
               else if(i==0 && j==0 )temp[j]=1;
                else{
                    int down=0,right=0;
                    if(i-1>=0)down=dp[j];
                    if(j-1>=0)right=temp[j-1];
                    
                    temp[j]=down+right;
                }
            }
            dp=temp;
        }
            return dp[n-1];
        
        
        
    }
    
    
    
    
    
    
    
    
//     int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        
//         int m=arr.size(),n=arr[0].size();
//         // vector<vector<int>>dp(m,vector<int>(n,-1));
//         // return solve(m-1,n-1,arr,dp);
//         vector<vector<int>>dp(m,vector<int>(n,0));
    
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
              
//                if(arr[i][j]==1)dp[i][j]=0;
//                else if(i==0 && j==0 )dp[i][j]=1;
//                 else{
//                     int down=0,right=0;
//                     if(i-1>=0)down=dp[i-1][j];
//                     if(j-1>=0)right=dp[i][j-1];
                    
//                     dp[i][j]=down+right;
//                 }
//             }
//         }
//             return dp[m-1][n-1];
         
//     }
};