class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
    int n=arr.size();
    unordered_map<int,bool>m;
    for(int i=0;i<n;i++)m[arr[i]]=true;
    for(int i=1;i<=n+1;i++){
        if(m[i]==false)return i;
      }
        return -1;
    }
};