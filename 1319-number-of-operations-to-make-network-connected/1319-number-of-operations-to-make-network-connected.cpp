 const int N=1e5+10;
int parent[N];
int sizes[N];
 
void make(int v){
  parent [v]=v;
  sizes[v]=1;
}
 
int find(int v){
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}
 
void Union(int a,int b){
 
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sizes[a]<sizes[b])swap(a,b);
        parent[b]=parent[a];
        sizes[a]+=sizes[b];
    }
}
 
class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        for(int i=0;i<n;i++)make(i);
        int k=connections.size();
        if(k<n-1)return -1;
        for(int i=0;i<k;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            Union(u,v);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(find(i)==i)c++;
        }
        return c-1;
    }
};