class Solution {
public:
    
    void bfs(int &i,int &j,vector<vector<int>>&vis,vector<vector<int>>&land){
        int n=land.size();
        int m=land[0].size();
        queue<pair<int,int>>q;
        vis[i][j]=1;
        q.push({i,j});
        
        vector<int>dx={0,0,-1,1};        
        vector<int>dy={-1,1,0,0};
    
        while(!q.empty()){
            
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nrow=row+dx[d];
                int ncol=col+dy[d];
                
                if(nrow<n && nrow>=0 && ncol<m &&ncol>=0 &&!vis[nrow][ncol] && land[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    if(nrow>i)i=nrow;
                    if(ncol>j)j=ncol;
                }

            }

            
        }
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>ans;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && land[i][j]==1 ){
                    int lrow=i;
                    int lcol=j;
                    bfs(lrow,lcol,vis,land);
                    ans.push_back({i,j,lrow,lcol});
                }
            }
        }
        return ans;
        
    }
};