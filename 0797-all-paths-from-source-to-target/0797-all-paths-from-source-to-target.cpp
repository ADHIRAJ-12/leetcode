class Solution {
public:
    vector<vector<int>> ans;
    vector<int>temp;
    int target;
    
    void dfs(vector<vector<int>>& graph, int node=0){
       
        temp.push_back(node);
        if(node==target)
            ans.push_back(temp);
        else {
            for(int currNode:graph[node]){
                dfs(graph,currNode);
            }
        }
        
        temp.pop_back(); 
        //backtracking
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        target=graph.size()-1;
        dfs(graph);
        return ans;
    }
};