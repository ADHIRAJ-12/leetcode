class Solution {
public:
   
    int makeTheIntegerZero(int num1, int num2) {
        
        
        for(int i=1;i<=60;i++){
            long long diff=(num1-num2*1LL*i);
            if(__builtin_popcountll(diff)<=i && i<=diff)return i;
        }
        return -1;
    }
};