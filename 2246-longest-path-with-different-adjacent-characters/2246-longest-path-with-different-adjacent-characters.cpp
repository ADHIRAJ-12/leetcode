class Solution {
public:
    int dist[100005];
    int ans=1;
    void dfs(int source,string& s,vector<vector<int>> &adj){
        dist[source]=1;
        for(auto nbr:adj[source]){
            dfs(nbr,s,adj);
            if(s[source]!=s[nbr]){
                ans=max(ans,dist[source]+dist[nbr]);
                dist[source]=max(dist[source],dist[nbr]+1);
            }
        }
    }
    
    
    int longestPath(vector<int>& parent, string s) {
        
        int n=parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0,s,adj);
        return ans;
    }
};