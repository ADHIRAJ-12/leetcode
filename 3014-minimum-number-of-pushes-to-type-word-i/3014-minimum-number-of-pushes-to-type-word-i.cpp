class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8)return n;
        
        int i = 1,q=n/8,r=n%8;
        int ans = 0;
        while (i <= q) {
            ans += 8 * i;
            i++; 
        }
    return (ans+(i*r));
    }
};