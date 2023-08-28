class Solution {
public:
    int timer=1;
    
    void dfs(int node,int par,vector<int>adj[],vector<int>&vis,
             vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges ){
        
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        
        for(auto i:adj[node]){
            if(i==par)continue;         //if nbr==parent continue
            if(vis[i]==0){
                dfs(i,node,adj,vis,tin,low,bridges);    //if not vis call dfs for it
                low[node]=min(low[node],low[i]);    //on returning from dfs update low of node
                if(tin[node]<low[i]){               //check if this edge is bridge
                    bridges.push_back({node,i});
                }
            }
            else{
                low[node]=min(low[node],low[i]);
            }
        }
        
    }
    
    
    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n+1];
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        vector<int>tin(n,0);
        vector<int>low(n,0);        
        vector<vector<int>>bridges;
        dfs(0,-1,adj,vis,tin,low,bridges);
        return bridges;
    }
};