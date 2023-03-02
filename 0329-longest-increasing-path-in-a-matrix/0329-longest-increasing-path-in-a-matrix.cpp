class Solution {
public:
    
    int solve(vector<vector<int>>& matrix,int row,int col,vector<vector<int>> &dp){
       int n=matrix.size();
       int m=matrix[0].size(); 
       int currMax=1;
        
        //check out of bounds condition
        if(row<0 || col<0 || row>=n || col>=m)return 0;
        
        //check if ans is present already in dp
        if(dp[row][col]!=0)return dp[row][col];
        
        //down
        if(row+1<n && row+1>=0 && matrix[row+1][col]>matrix[row][col]  ){
            currMax=max(currMax,1+solve(matrix,row+1,col,dp));
        }
        
        //up
        if(row-1<n && row-1>=0 && matrix[row-1][col]>matrix[row][col]  ){
            currMax=max(currMax,1+solve(matrix,row-1,col,dp));
        }
        
        
        //right
        if(col+1<m && col+1>=0 && matrix[row][col+1]>matrix[row][col]  ){
            currMax=max(currMax,1+solve(matrix,row,col+1,dp));
        }
    
        
        //left
        if(col-1<m && col-1>=0 && matrix[row][col-1]>matrix[row][col]  ){
            currMax=max(currMax,1+solve(matrix,row,col-1,dp));
        }
        
        //store ans in dp and return 
        return dp[row][col]=currMax;
        
    }
    
    
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();   

       vector<vector<int>>dp(n,vector<int>(m,0));
       int maxi=0;
       
        //check for ever columns if its neighbours form an increasing sequence
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            maxi=max(maxi,solve(matrix,i,j,dp));
            }
        }
        
       return maxi; 
    }
};