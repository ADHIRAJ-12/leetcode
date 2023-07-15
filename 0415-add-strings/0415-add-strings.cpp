class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() , n = num2.size();
        int x = abs(m-n);
        string t = "";
        //make 2 strings equal by adding zeroes
      if(x!=0)
      {
        for(int i = 1; i<=x ;i++)t+='0';
        if(n>m) num1 = t+num1;
        else num2 = t+num2;
        
      }
        //interate fromo back and add numbers by managing carry
      vector<int> res(num1.size()+1,0);
      int k = res.size()-1;
      for(int i = num1.size()-1 ; i>=0 ; i--)
      { 
        int val = (num1[i]-'0')+(num2[i]-'0')+res[k];
        if(val>=10)
        {
            int t = val-10;
            res[k] = t;
            k--;
            res[k]+=1;
        }
        else{
            res[k] = val;
            k--;
        }
      }
    int i = 0;
    string ans = "";
    if(res[k]==0 && res[k+1]==0) return "0";
    while(res[i]==0) i++;
    for( ;i<res.size();i++)
    {
        ans+=to_string(res[i]);
    }
    return ans;
}
};