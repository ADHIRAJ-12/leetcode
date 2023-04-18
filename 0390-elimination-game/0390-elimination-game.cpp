class Solution {
public:
    int lastRemaining(int n) {
        
       int start=1,diff=1,total=n;
         bool L2R=true;
        while(total>1){
            if(L2R||total%2==1)
                start+=diff;
            diff*=2;
            total/=2;
            L2R=!L2R;
        }
        return start;
        
    }
};