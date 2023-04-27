class Solution {
public:
    
    int binExp(int a,int b,int m){
        a%=m;
        int ans=1;
        while(b>0){
            if(b&1){
                ans=(ans*1LL*a)%m;
            }
            a=(a*1LL*a)%m;
            b>>=1;
        }
        return ans;
    }
    
    int superPow(int a, vector<int>& b) {
        
        int bmod=0;
        for(int i:b){ 
            bmod=(bmod*10+i)%1140; 
            //binary exponentialtion
            //a^b %m =(a^(b%phi(m))%m;
            //1337=191*7 => phi(1337)=1337 *(1-1/7)*(1-1/191)=1140
        }
        return binExp(a,bmod,1337);
        
    }
};