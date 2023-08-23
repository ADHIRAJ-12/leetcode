class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        //dijkstras
        int n=grid.size(),m=grid[0].size();
        queue< pair<int,pair<int,int>> >mini;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
       vector<int>dx={-1,-1,-1,0,0,1,1,1};       
        vector<int>dy={-1,0,1,-1,1,-1,0,1};
            
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        
        mini.push({0,{0,0}});
        
        while(!mini.empty()){
            int dis=mini.front().first;
            int row=mini.front().second.first;
            int col=mini.front().second.second;
            mini.pop();
            
            // if(row==n-1 && col==m-1)return dis+1; 
            
            for(int i=0;i<8;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if(nrow<n && nrow>=0 &&ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                     mini.push({dis+1,{nrow,ncol}});

                }
            }

        }
        
        if(dist[n-1][m-1] == 1e9) return -1;
        return dist[n-1][n-1]+1;
    }
};



//                  basic dfs

//         int n=grid.size(),m=grid[0].size();
//         vector<int>dx={-1,-1,-1,0,0,1,1,1};       
//         vector<int>dy={-1,0,1,-1,1,-1,0,1};

//         if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        
//         queue< pair<int,pair<int,int>> >mini;
//         mini.push({0,{0,0}});
        
//         while(!mini.empty()){
//             int dis=mini.front().first;
//             int row=mini.front().second.first;
//             int col=mini.front().second.second;
//             mini.pop();
            
//             if(row==n-1 && col==m-1)return dis+1; 
            
//             for(int i=0;i<8;i++){
//                 int nrow=row+dx[i];
//                 int ncol=col+dy[i];
                
                
//                 if(nrow<n && nrow>=0 &&ncol>=0 && ncol<m && grid[nrow][ncol]==0){
//                     mini.push({dis+1,{nrow,ncol}});
//                      grid[nrow][ncol]=1;
//                 }
//             }

//         }
        
        
//         return -1;