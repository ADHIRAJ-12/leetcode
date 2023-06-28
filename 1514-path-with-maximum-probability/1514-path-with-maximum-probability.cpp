class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> adj(n); //adj list creation
        int m = edges.size();
        
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        //applying modified djikstra's algo

        vector<int>vis(n,0);
        vector<double>prob(n,0.0);
        set<pair<double,int>>st;
        st.insert({0,start});
        prob[start]=1.0;
        
        
        while(!st.empty()){
            
           auto frontNode=*st.begin();
            st.erase(st.begin());
            
            int u=frontNode.second;
            
            if(vis[u]) continue;
            vis[u]=true;
            
            for(auto &child:adj[u]){
                int v=child.first;
                double weight=child.second;
                
                //condition check
                if(prob[u]*weight>prob[v]){
                    prob[v]=prob[u]*weight;
                    st.insert({1.0-prob[v],v});
                }
                
            }
            
        
        }    
    return prob[end];
    }
};