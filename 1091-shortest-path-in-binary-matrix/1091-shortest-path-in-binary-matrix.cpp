class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        vector<int>dx={-1,-1,-1,0,0,1,1,1};       
        vector<int>dy={-1,0,1,-1,1,-1,0,1};

        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        
priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >mini;
        mini.push({0,{0,0}});
        
        while(!mini.empty()){
            int dis=mini.top().first;
            int row=mini.top().second.first;
            int col=mini.top().second.second;
            mini.pop();
            
            if(row==n-1 && col==m-1)return dis+1; 
            
            for(int i=0;i<8;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                
                if(nrow<n && nrow>=0 &&ncol>=0 && ncol<m && grid[nrow][ncol]==0){
                    mini.push({dis+1,{nrow,ncol}});
                     grid[nrow][ncol]=1;
                }
            }

        }
        
        
        return -1;
    }
};