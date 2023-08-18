class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                    
                }
                else vis[i][j]=0;
            }
        }
     int time=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second; 
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dir[i][0];
                int ncol=col+dir[i][1];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;                    
                }
            }
   
        }
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
               if(grid[i][j]==1 && vis[i][j]!=2)return -1; 
            }
         }
        
        return time;
    }
};