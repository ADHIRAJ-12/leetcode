class Solution {
public:
    
    
    int dist(vector<int>&a,vector<int>&b){
        return abs(abs(a[0]-b[0]) + abs(a[1]-b[1]));
    }
                
                
     int prims(vector<pair<int,int>>adj[],int &v) {
        
        vector<int>vis(v,0); 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
        mini.push({0,0});
        int sum=0, nodes = 0;
        
        while(!mini.empty() && nodes<v){
            int wt=mini.top().first;
            int node=mini.top().second;
            mini.pop();
            
            if(vis[node])continue;
            vis[node]=1;
            nodes++;
            sum+=wt;

            
            for(auto i:adj[node]){
                int weight=i.second;
                int nbr=i.first;
                
                if(!vis[nbr]){
                    mini.push({weight,nbr});
                    
                }
            }
            
        }
        
        return sum;
                
    }   
                
                
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
//         vector<pair<int,int>>adj[n];
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 adj[i].push_back({j,dist(points[i],points[j])});
//                 adj[j].push_back({j,dist(points[j],points[j])});
//             }
//         }
        
        
//          return prims(adj, n);
 
        int n=points.size();
        vector<pair<int,int>>adj[n];
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int w = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
        return prims(adj, n);
        
        
    }
};