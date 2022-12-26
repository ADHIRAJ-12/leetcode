class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int n=deliciousness.size();
        int MOD = 1e9 + 7;
         
        unordered_map<int,int>m;
        int count=0;
      
        for(int i=0;i<n;i++){
            int power=1;
            for(int j=0;j<=21;j++){
                if(m.find(power-deliciousness[i])!=m.end()){
                    // y= 2ki power - elemnt, agar map me y mil jaye to count increase krdo us pair ka
                    count=count+m[power-deliciousness[i]];
                    count=count%MOD;  //mod acc to ques
                }
                power=power*2; // increase power of 2
            }
            m[deliciousness[i]]++;  //map me add krdo us elemet ko
        }
        return count;
        
        
    }
};