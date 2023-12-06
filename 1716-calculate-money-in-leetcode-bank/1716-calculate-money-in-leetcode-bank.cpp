class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int count=1,nn=0;
        while(nn!=n){
            
            for(int i=count;i<7+count;i++){
                sum+=i;
                nn++;
                if(nn==n)break;
            }
                count++;           
        }
        return sum;
    }
};