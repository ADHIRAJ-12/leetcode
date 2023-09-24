class Solution {
public:
    
    int count(int i,int j,int m,int n,vector<vector<int>> &dp ){
        
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        else return dp[i][j]=count(i+1,j,m,n,dp)+count(i,j+1,m,n,dp);

}
    
    
    int uniquePaths(int m, int n) {

         vector<vector<int>>dp(m,vector<int>(n,-1));
         return count(0,0,m,n,dp);
        
    }
};













        
//      //solving paths from star to the robot
        
//     int dp[m][n];
        
//     for(int i=0;i<m;i++){
//      for(int j=0;j<n;j++){
             
          //1st row and 1st colm have only one movement direction so ans=1 at these places
   
        // if(i==0 ||j==0) dp[i][j]=1;
             
//             else dp[i][j]=dp[i-1][j]+dp[i][j-1];
//          }
//       }
//         return dp[m-1][n-1];    // returning ans stored at the last index after fillig thr whole table;