class Solution {
public:
       vector<vector<string>>ans1;
        vector<string>x;
       bool isPalindrome(int i,int j,string s){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
        
    }
    return true;
    
}


 void f(int i,int n,string &s){
     
     if(i==n){
          {
            ans1.push_back(x);
            return;
        }
     }
     string temp="";
     
     
    //  if(dp[i]!=-1)return dp[i];

     for(int j=i;j<n;j++){
         temp+=s[j];
         if(isPalindrome(i,j,s)){
          x.push_back(temp);
                f(j+1,n,s);
                x.pop_back();
         }
     }
  
 }
    vector<vector<string>> partition(string s) {
        
         int n =s.size();
       f(0,n,s); 
      return ans1;
    
    }
};