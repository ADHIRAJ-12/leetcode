class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        if(n!=m)return false ; 

        vector<int> m1(26) , m2(26) ; 

        for(char ch : word1)
        m1[ch - 'a']++;

        for(char ch : word2){
            int val = m1[ch - 'a'];
             
            if(val == 0)
            return false ;

            m2[ch - 'a']++;
        }

        sort(m1.begin() , m1.end());
        sort(m2.begin() , m2.end());

        for(int i = 0 ; i < 26 ; i++) {
            if(m1[i] != m2[i] )
            return false ;
        }
     return true ; 
        
    }
};