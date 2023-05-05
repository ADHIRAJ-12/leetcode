class Solution {
public:
    
    bool static cmp(vector<int>&a,vector<int>&b){
        if(a[1]<b[1])return true;
        else return false;
        
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
       int n=pairs.size();
       sort(pairs.begin(),pairs.end(),cmp);
        
        int len=1;
        auto last=pairs[0];
        for(int i=0;i<n;i++){
            if(pairs[i][0]>last[1]){
                last=pairs[i];
                len++;
            }
        }
        return len;
    }
};