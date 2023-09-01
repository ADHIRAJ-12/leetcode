class Solution {
public:
    
bool bfs(int i,int j,vector<vector<int>>& grid2,vector<vector<int>>&grid1){
     
        int n=grid1.size();
        int m=grid1[0].size();
    
        queue<pair<int,int>>q;
        q.push({i,j});
        
        bool flag=true;
        vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
    
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int d=0;d<4;d++){
                int nrow=row+dir[d][0];
                int ncol=col+dir[d][1];
                
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid2[nrow][ncol]==1){
                    
                if(grid1[nrow][ncol]==0)flag=false;
                else{
                    grid1[nrow][ncol]=0;
                    grid2[nrow][ncol]=0;
                    q.push({nrow,ncol});
                }
                
                }

            }

        }
            return flag;
    
    }
    

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        
        int count=0;
        
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[i].size();j++){
                if(grid1[i][j] && grid2[i][j]){
                    count+=bfs(i,j,grid2,grid1);
                }
            }
        }
        return count;
    }
};