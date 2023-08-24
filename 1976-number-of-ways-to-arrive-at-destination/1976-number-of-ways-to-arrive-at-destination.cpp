class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 +7;
        vector<vector<long long>> adj[n+1];
        
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({ roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({ roads[i][0],roads[i][2]});
        }
        
        vector<long long> ways(n,0);
        ways[0] = 1;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> mini;
        mini.push({0, 0}); 
        
        while(! mini.empty()){
            long long node=  mini.top()[1];
            long long diss=  mini.top()[0];
             mini.pop();
                        
            for(auto i : adj[node]){
                long long nbr = i[0];
                long long wt = i[1];
                if( diss + wt < dist[nbr]){
                    dist[nbr] = diss + wt;
                    mini.push({diss+wt,nbr});
                    ways[nbr] = ways[node]%MOD;
                }
                else if(diss + wt == dist[nbr]){
                    ways[nbr] += (ways[node])%MOD;   
                }
            }
        }
        
        return ways[n-1]%MOD;
        
    }
};