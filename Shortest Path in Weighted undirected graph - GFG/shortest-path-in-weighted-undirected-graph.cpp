//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>dist(n+1);
        vector<int>par(n+1);
        
        for(int i=1;i<=n;i++){
            par[i]=i;
            dist[i]=1e9;
        }
        dist[1]=0;
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
        mini.push({0,1});
        
        while(!mini.empty()){
            int dis=mini.top().first;
            int node=mini.top().second;
            mini.pop();
            
            for(auto i:adj[node]){
                
                int wt=i.second;
                int nbr=i.first;
                if(dist[nbr]>wt+dis){
                    dist[nbr]=wt+dis;
                    par[nbr]=node;
                    mini.push({dist[nbr],nbr});
                }
            }
        }
        if(dist[n]==1e9)return {-1};
        vector<int>ans;
        int node=n;
        while(par[node]!=node){
            ans.push_back(node);
            node=par[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        
                    
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends