class Solution {
public:
    
    bool bfs(int start,vector<vector<int>>& adj,vector<int>&color){
        
        queue<int>q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty()){
            int node =q.front();
            q.pop();
            
            for(auto i:adj[node]){
                if(color[i]==-1){
                    color[i]=!color[node];
                    q.push(i);
                }
                
                else if(color[i]==color[node])return false;
            }
            
            
        }
        return true;

    }
    

    bool isBipartite(vector<vector<int>>& adj) {
        
        int n=adj.size();

        // vector<int>adj[n];
        
//         //preparing adj list
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
                
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
                
//             }
//         }
        
        //color vector
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,adj,color)==false)return false;
            }
        }
        return true;
        
    }
};