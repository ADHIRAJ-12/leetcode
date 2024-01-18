class Solution {
public:
    int climbStairs(int n) {
        
        if(n<=2)return n;
        
        int first=1,second=2;
        for(int i=3;i<n;i++){
            
            int res=second;
            second=second+first;
            first=res;
        }
        return first+second;
        
    }
};