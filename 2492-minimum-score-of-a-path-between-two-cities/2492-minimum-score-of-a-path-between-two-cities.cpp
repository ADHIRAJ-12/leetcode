class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
 
        
        unordered_map<int,vector<pair<int,int>>>adj;
        
        for(auto i:roads){

            int u=i[0];
            int v=i[1];
            int w=i[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
          }
        
        
        unordered_set<int>vis;
        int ans=INT_MAX;
        queue<int>q;
        q.push(1);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis.insert(node);
            
            for(auto nbr:adj[node]){
                if(vis.count(nbr.first))continue;
                
                ans=min(ans,nbr.second);
                q.push(nbr.first);
            }
        }
        return ans;
        
          
        
        
    }
};