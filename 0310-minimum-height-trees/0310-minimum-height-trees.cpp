class Solution {
public:
    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n+1];
        vector<int>deg(n+1,0);
    
        if(n == 1)return {0};
        
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]); 
            deg[i[0]]++;
            deg[i[1]]++;

        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==1)q.push(i);
        }
        vector <int> res;                   
        while(!q.empty())
        {
            res.clear();
            int size=q.size();
            while(size--)           
            {
                int node=q.front();
                q.pop();
                res.push_back(node); 
                for(auto &nbr:adj[node])
                {
                    deg[nbr]--;            
                    if(deg[nbr]==1)        
                        q.push(nbr);
                }
            }
        }
        return res;
        
    }
};