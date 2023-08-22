class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        
        queue<int>q;
        vector<int>indeg(n,0);
       vector<set<int>> ancestor(n);
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++){
            {
                if(indeg[i]==0)q.push(i);
                 ancestor[i] = {};   
            }
        
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            
            
            for(auto i:adj[node]){
                indeg[i]--;
                if(indeg[i]==0)q.push(i);
                
                
                
                // the ancestor of the curr node will be ancestor od nbr
                for(auto anc:ancestor[node]){
                    ancestor[i].insert(anc);
                }
                //curr node will be ancestor of the neighbour
                ancestor[i].insert(node);
                
            }
            
            
        }
       vector<vector<int>> res(n);
        for(int i = 0;i<ancestor.size();i++){
            for(auto j : ancestor[i]){
                res[i].push_back(j);
            }
        }
        return res;
  
    }
};