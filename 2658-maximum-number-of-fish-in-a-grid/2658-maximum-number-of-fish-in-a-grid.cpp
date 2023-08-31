class Solution {
public:
    

    
    int findMaxFish(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
     
          vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    int sum=0;
                    bfs(i,j,sum,vis,grid);
                    maxi=max(maxi,sum);
                }
        }
    }
       
    return maxi;
       
       
    }
    
        void bfs(int i,int j,int &sum,vector<vector<int>>&vis,vector<vector<int>> grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        sum+=grid[i][j];
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            vector<int> dx = {-1, 1, 0, 0};
            vector<int> dy = {0, 0, -1, 1};
            
            for(int i=0;i<4;i++){
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];
                    
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]>0){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
                sum+=grid[nrow][ncol];
                }
            }            
        }
        
    }
    
    
    
    
};