class Solution {
public:
    bool detectCapitalUse(string word) {
        
        
        int count=0,n=word.size();
        for(int i=0;i<n;i++)
            if(word[i]>='A' && word[i]<='Z')count++;
            
        if(count==n ||count==0||count==1 &&word[0]>='A' && word[0]<='Z')return true;
        
        return false;
    }
};