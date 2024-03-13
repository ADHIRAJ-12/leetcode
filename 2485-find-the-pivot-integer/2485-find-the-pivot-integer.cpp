class Solution {
public:

    
    int pivotInteger(int n) {
        
        if(n==1)return 1;
        int k=n/2;
        
        while(k<=n){
            int sum=(k*(k+1))/2;
            int sum2=0;
            for(int j=k;j<=n;j++){
                sum2+=j;
            }
               if(sum==sum2)return k;
            k++;
        }
        
        return -1;
        
    }
};