class Solution {
public:
    int minOperations(int n) {

     if(n%2)return n/2*(1+(n/2));
        return n/2*(n/2); 
        
        
    }
};