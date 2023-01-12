class Solution {
public:
     void dfs(string&labels, vector<vector<int>>&adj, vector<int>&ans,vector<int>&mymap,int curr,int prev){
       int prevCount = mymap[labels[curr]-'a'];
       mymap[labels[curr]-'a']++;
       for(auto nbr : adj[curr]){
          if(nbr!= prev){
              dfs(labels,adj,ans,mymap,nbr,curr);
          } 
       }
       ans[curr] = mymap[labels[curr]-'a']-prevCount;
    }
    
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels){
        vector<vector<int>>adj(n);
        for(auto src : edges) {
            adj[src[0]].push_back(src[1]);
            adj[src[1]].push_back(src[0]);
        }
        
        vector<int>ans(n);
        vector<int>mymap(26,0);
        dfs(labels,adj,ans,mymap,0,-1);
        return ans;
        }
};