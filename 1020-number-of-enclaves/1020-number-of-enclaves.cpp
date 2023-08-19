class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0|| j==0||i==n-1||j==m-1 )&& grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        
        
        while(!q.empty()){
            
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            vis[row][col]=1;
            
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if(nrow>=0 &&nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1 ){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

        }
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==1)c++;
            }
        }
        return c;
        
    }
};