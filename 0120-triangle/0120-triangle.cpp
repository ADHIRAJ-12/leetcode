class Solution {
public:
    
//         int f(int i,int j,vector<vector<int>>& triangle, int n,vector<vector<int>> &dp){

//             if(i==n-1) return triangle[n-1][j];

//             if(dp[i][j]!=-1)return dp[i][j];

//             int down=triangle[i][j]+f(i+1,j,triangle,n,dp);
//             int daig=triangle[i][j]+f(i+1,j+1,triangle,n,dp);

//             return dp[i][j]= min(down,daig);
//         }
    
    
//         int minimumTotal(vector<vector<int>>& triangle) {

//              int n=triangle.size();
//              // vector<vector<int>>dp(n,vector<int>(n,-1));
//              // return f(0,0,triangle,n,dp);
//             vector<vector<int>>dp(n,vector<int>(n,0));
//             for(int i=0;i<n;i++){
//                  dp[n-1][i]=triangle[n-1][i];
//             }
           
            
//             for(int i=n-2;i>=0;i--){
//                 for(int j=0;j<=i;j++){
//                      int down=triangle[i][j]+dp[i+1][j];
//                      int daig=triangle[i][j]+dp[i+1][j+1];
                    
//                     dp[i][j]=min(down,daig);
//                 }
//             }
//             return dp[0][0];
//         }
    
    int minimumTotal(vector<vector<int>>& triangle) {

             int n=triangle.size();
      
            vector<int>dp(n,0);
            for(int i=0;i<n;i++){
                 dp[i]=triangle[n-1][i];
            }
           
            
            for(int i=n-2;i>=0;i--){
                 vector<int>temp(n,0);
                for(int j=0;j<=i;j++){
                     int down=triangle[i][j]+dp[j];
                     int daig=triangle[i][j]+dp[j+1];
                    
                    temp[j]=min(down,daig);
                }
                dp=temp;
            }
        
            return dp[0];
        }
    
};