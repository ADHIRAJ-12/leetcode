
     unordered_map<char,int>m;
     static bool cmp(string a,string b){
       int n=a.length(),p=b.length();
        int len=min(n,p);
         
        for(int i=0;i<len;i++){
            if(m[a[i]] < m[b[i]])return true;
            
            else if(m[a[i]]>m[b[i]])return false;
        }
        
        if(n<=p)return true;
        return false;
    }
class Solution {
public:
    
    bool isAlienSorted(vector<string>& words, string order) {
        int n=order.length();
        for(int i=0;i<n;i++)m[order[i]]=i;
        
        vector<string> compare=words;
        sort(compare.begin(),compare.end(),cmp);
        return compare==words;
    }
};