class Solution {
public:

    int longestSubstring(string s, int k) {
        int n=s.length();

        //store freq of each char in a map
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[s[i]]++;
        
        //traverse in string till index<n and count of char aperance in map is >=k
        int i=0;
        while(i<n && m[s[i]]>=k)i++;
        
        //if we reach end of string return length of strig as ans;
        if(i==n)return n;
        
        //else ans can be 0 to index-1 OR index+1 to end.retrun max of that
        else return max(longestSubstring(s.substr(0,i),k),longestSubstring(s.substr(i+1),k));
        
        
    }
};