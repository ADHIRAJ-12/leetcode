class Solution {
public:
    

    int mySqrt(int n) {
       
        int s=0,e=n;

        while (s<=e){

            long long mid=s+(e-s)/2;

            if(mid*mid<=n)s=mid+1;
            else e=mid-1;

        }
        return e;
        
    }
};