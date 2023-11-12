
class Solution {
private:
  void uncoverCycle(unordered_map<int, unordered_set<int>>& graph) {
    int n = graph.size();
    vector<int> remove = {};                           //returning this as ans
    for (auto& k : graph) {
      int node = k.first;
      auto& adjlist = k.second;
      if (adjlist.size() == 1) {                       // leaf node
        remove.push_back(node);
        auto er = adjlist.begin();
        graph[*er].erase(node);
      }
    }

    if (remove.empty()) return;
    else {
      for (int node : remove) graph.erase(node);      //erasing
      uncoverCycle(graph);
    }
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
                                                            //the node which will is forming the cycle has to be removed
    int n = edges.size();
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < n; ++i) {                          // for list of connections
      graph[edges[i][0]].insert(edges[i][1]);
      graph[edges[i][1]].insert(edges[i][0]);
    }
      
                                                           // for removing leaf nodes to know where the cycle id forming
    uncoverCycle(graph);

    for (int i = n - 1; i >= 0; --i) {                    //remove nodes from  the  end
      if (graph.count(edges[i][0]) && graph.count(edges[i][1])) return edges[i];
    }                                                     // findind if the edge exists or not

    return {};
  }
};




     

      

