class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
       vector<vector<int>>dx={{0,1},{1,0},{-1,0},{0,-1}};
        
priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >mini;
        mini.push({0,{0,0}});
        
        
         while(!mini.empty()){
            int diff=mini.top().first;
            int row=mini.top().second.first;
            int col=mini.top().second.second;
            mini.pop();
            
            if(row==n-1 && col==m-1)return diff; 
            
            for(int i=0;i<4;i++){
                int nrow=row+dx[i][0];
                int ncol=col+dx[i][1];
                
                
                    if(nrow<n && nrow>=0 &&ncol>=0 && ncol<m ){
                   int newdiff=max(abs( heights[row][col]-heights[nrow][ncol]),diff);
                    if(newdiff<dist[nrow][ncol]){
                        dist[nrow][ncol]=newdiff;
                        mini.push({newdiff,{nrow,ncol}});
                        }
                    }
                      
            }

        }
        return 0;
        
    }
};