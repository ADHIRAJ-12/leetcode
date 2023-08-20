class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
         vector<int>adj[n];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>ans;
        vector<int>indegree(n,0);
        queue<int>q;
        
        for(int i=0;i<n;i++){
            for(auto node:adj[i]){
                indegree[node]++;
            }
        }
        
        for(int i=0;i<n;i++){
                if(indegree[i]==0)q.push(i);
        }
        
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        // sort(ans.begin(),ans.end());
        if( ans.size()==n)return ans;
        else return {};
    }
};