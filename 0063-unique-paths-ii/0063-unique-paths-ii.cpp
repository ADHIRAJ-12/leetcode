class Solution {
public:
 
    int f(int i,int j,vector<vector<int>>& matrix, vector<vector<int>> &dp){

       int n=matrix.size();
       int m=matrix[0].size();

        
        if(i==n-1 && j==m-1 && matrix[i][j]!=1)return 1;

        if(i>=n ||j>=m || matrix[i][j]==1)return 0;
        if(matrix[n-1][m-1] == 1)return 0;

           if(dp[i][j]!=-1)return dp[i][j];

        else return dp[i][j]=f(i,j+1,matrix,dp)+f(i+1,j,matrix,dp);
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int n=obstacleGrid.size();
       int m=obstacleGrid[0].size();
       
    vector<vector<int>>dp(n,vector<int>(m,-1));
     return f(0,0,obstacleGrid,dp);        
        
    }
};