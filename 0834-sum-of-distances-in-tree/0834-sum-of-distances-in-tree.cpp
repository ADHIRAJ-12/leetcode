class Solution {
public:
   int siz;
    vector<int>ans,count;
    void dfs(int src,int parent,vector<int> adj[]){
        
        for(auto& child:adj[src]){
            if(child!=parent){
                dfs(child,src,adj);
                count[src]+=count[child];
                ans[src]+=ans[child]+count[child];
            }
        }   
    }
    
    
      void dfs2(int src,int parent,vector<int> adj[]){
        
        for(auto& child:adj[src]){
            if(child!=parent){
               ans[child]+=(ans[src]+(siz-count[child])-ans[child]-count[child]);
                dfs2(child,src,adj);
            }
        }   
    }
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        siz=n;
        vector<int>adj[n];
        ans.resize(n,0);
        count.resize(n,1);

        
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        dfs(0,-1,adj);
        dfs2(0,-1,adj);
        return ans;
        
    }
};