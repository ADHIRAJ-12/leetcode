class Solution {
public:
bool iscyclic(int node,vector<int> adj[],vector<int> &visited,vector<int> &dfsvisited){
visited[node]=true;
dfsvisited[node]=true;
for(auto nbr:adj[node]){
if(!visited[nbr]){
if(iscyclic(nbr,adj,visited,dfsvisited))return true;
}
else if(dfsvisited[nbr]==true)return true;
}
dfsvisited[node]=2;
return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//if there exists a cycle in the graph then schedule is not possible
//so basically we have to check if cycle exists or not
vector<int>adj[numCourses];
​
for(int i=0;i<prerequisites.size();i++)
adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
vector<int>visited(numCourses,0);
vector<int>dfsvisited(numCourses,0);
​
for(int i=0;i<numCourses;i++){
if(!visited[i]){
if(iscyclic(i,adj,visited,dfsvisited))return false;
}
}
return true;
}
};