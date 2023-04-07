class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans(m*n);

        if(n==0||m==0)return {};
        int i=0,row=0,col=0;
        bool up=true;
         
        while(row<m && col<n){
            
            //moving upward
            if(up){
                
                while(row>0 && col<n-1){
                    ans[i++]=mat[row][col];
                    row--;
                    col++;
                }
                 ans[i++]=mat[row][col];
                if(col==n-1){
                    row++;
                }
                
                else{  
                    col++;
                }
            }
            //down
            else{
                while(col>0 && row<m-1 ){
                    ans[i++]=mat[row][col];
                    row++;
                    col--;
                }
                 ans[i++]=mat[row][col];
                if(row==m-1){
                    col++;
                }
                
                else {
                    row++;
                     }
                
            }
            
            up=!up;
            
        }
        
        return ans;
    }
};