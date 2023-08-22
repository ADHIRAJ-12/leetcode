//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        
        vector<int>dist(v,1e9);
        dist[s]=0;
        
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
        mini.push({0,s});
        
        while(!mini.empty()){
            int dis=mini.top().first;
            int node=mini.top().second;
            mini.pop();
            
            for(auto i:adj[node]){
                
                int wt=i[1];
                int nbr=i[0];
                if(dist[nbr]>wt+dis){
                    dist[nbr]=wt+dis;
                    mini.push({dist[nbr],nbr});
                }
            }
        }
        
        
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends