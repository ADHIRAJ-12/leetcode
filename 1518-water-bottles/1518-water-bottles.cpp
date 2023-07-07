class Solution {
public:
    int numWaterBottles(int n, int m) {
        
        int ans=0,left = 0;
        while(n>0)
        {
            ans += n;
            left += n;
            n = (left/m);
            left = left%m;
        }
        
        return ans;
    }
};