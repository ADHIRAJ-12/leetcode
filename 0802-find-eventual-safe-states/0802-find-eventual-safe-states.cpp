class Solution {
public:
    
    
    bool dfs(int node,vector<int>&vis,vector<int>&path,vector<vector<int>>& adj,vector<int>& markSafe){
    
    vis[node]=1;
    path[node]=1;    

        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i,vis,path,adj,markSafe))return true;
            }
            else if(path[i]==1)return true;
        }


        path[node]=0;
        markSafe[node]=1;
        return false;
}
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        
        int n=adj.size();
        vector<int>ans;
        vector<int>vis(n+1,0);
        vector<int>path(n+1,0);
        vector<int>markSafe(n+1,0);

        for(int i=0;i<=n;i++){
            if(!vis[i]){
                dfs(i,vis,path,adj,markSafe);
            }
        }
    
        for(int i=0;i<n;i++){
            if(markSafe[i] )ans.push_back(i);
        }
        return ans;
    }
};