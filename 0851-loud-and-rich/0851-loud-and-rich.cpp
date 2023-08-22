class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& edges, vector<int>& quiet) {
        
        
        int n=quiet.size();
        queue<int>q;
        vector<int>indeg(n,0);
        vector<int>res(n);
         vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++){
                res[i]=i;
                if(indeg[i]==0){
                    q.push(i);
                }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto i:adj[node]){
              
               if(quiet[res[node]] < quiet[res[i]]){
                    res[i]=res[node];
                }
                  indeg[i]--;
                if(indeg[i]==0)q.push(i);
   
            }
        }
        
        return res;
        
        
    }
};