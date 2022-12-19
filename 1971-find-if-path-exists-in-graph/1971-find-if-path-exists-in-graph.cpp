class Solution {
public:
    
 
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
         
        vector<bool>visited(n,0);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
            if(top==destination)return true;
            
            for(auto nbr:adj[top]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        return false;
        
    }
};