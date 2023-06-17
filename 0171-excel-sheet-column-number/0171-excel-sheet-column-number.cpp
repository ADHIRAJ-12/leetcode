class Solution {
public:
    int titleToNumber(string str) {
        
    long long ans=0;
     for(char c:str){
         int dig=c-'A'+1;
         ans=ans*26+dig;
     }
     return ans;
    }
};