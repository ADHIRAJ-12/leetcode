class Solution {
public:
    
    bool checkPal(int n){
        
        string str=to_string(n);
        if(str.size()==1)return true;
        
        int s=0,e=str.size()-1;
        while(s<=e){
            if(str[s]!=str[e])return false;
            
            s++;
            e--;
        }
        return true;
    } 
    
    int baseConvert(int n, int base){
        long  res = 0;
        int i = 0;
        while (n != 0)
        {
            if(res<INT_MAX/10)
                res = res + (n % base) * pow(10, i);
            i++;
            n = n / base;
        }
        return res;
    }
    
    bool isStrictlyPalindromic(int n) {
       
        for(int i=2;i<=n-2;i++){
           if(checkPal(baseConvert(n,i))==0)return false;
       } 
        return true;
    }
};