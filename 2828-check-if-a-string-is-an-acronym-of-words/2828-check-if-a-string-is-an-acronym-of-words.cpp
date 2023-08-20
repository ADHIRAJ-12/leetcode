class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int i=0,j=0;
        string str="";
        for(int i=0;i<words.size();i++){
             str+=words[i][0];
        }
        if(str==s)return true;
        else return false;
    }
};