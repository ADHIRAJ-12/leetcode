//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    void dfs(int node,vector<int>&vis,vector<vector<int>>& adj,stack<int>&st){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i])dfs(i,vis,adj,st);
        }
        
        
        st.push(node);
    }
    
    void dfst(int node,vector<int>&vis,vector<int>adjt[]){
        vis[node]=1;
        for(auto i:adjt[node]){
            if(!vis[i])dfst(i,vis,adjt);
        }
    }
    
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(n,0);
        stack<int>st;
        //sort in order of time
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,vis,adj,st);
        }
        
        //reverse graph
        vector<int>adjt[n+1];
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(auto node:adj[i]){
                adjt[node].push_back(i);
            }
        }
        //call dfs witj scc counter
        int scc=0;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                scc++;
                dfst(i,vis,adjt);
            }
        }
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends