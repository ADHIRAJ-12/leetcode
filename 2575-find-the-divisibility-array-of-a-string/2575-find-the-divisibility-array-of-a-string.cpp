class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        
        int n=word.size();
        long long rem=0;
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            int digit=word[i]-'0';
            rem=(rem*10+digit)%m;
            if(rem==0)ans[i]=1;
            
        }
        return ans;
        
    }
};

 
        
             //logic
// digit = quotient*m + remainder
// new digit= n*10 + new
// = (quotient*m + remainder) * 10 + new
// = 10 *quotient*m + 10remainder + new