class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int>indegree(n,0);
        vector<int>ans;
        for(auto i:edges){
            indegree[i[1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)ans.push_back(i);
            }
        return ans;
    }
};

//node with indegree 0 are our ans