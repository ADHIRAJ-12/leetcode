//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void f(int i,int j,vector<vector<int>> &m,int n,string move,vector<string>&path,vector<vector<int>>&vis,
    vector<int>&dx,vector<int>&dy){
        
        
        if(i==n-1 && j==n-1){
            path.push_back(move);
            return;
        }
        
        string str="DLRU";
        for(int d=0;d<4;d++){
            int nexti=i+dx[d];
            int nextj=j+dy[d];
            
            if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && !vis[nexti][nextj] && m[nexti][nextj]==1){
                    vis[i][j]=1;
                    f(nexti,nextj,m,n,move+str[d],path,vis,dx,dy);
                    vis[i][j]=0;
            }
        }
    }
    
    
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>path;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<int>dx={1,0,0,-1};
        vector<int>dy={0,-1,1,0};
        string move="";
        if(m[0][0]==1)f(0,0,m,n,move,path,vis,dx,dy);
        return path;
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends