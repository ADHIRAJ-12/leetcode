class Solution {
public:
    int maxLengthBetweenEqualCharacters(string str) {
        int maxi=-1;
        for(int i=0;i<str.length();i++){
           
            for(int j=i+1;j<str.length();j++){
                if(str[j]==str[i]){
                    maxi=max(maxi,j-i-1);
                }
            }
        }
        return maxi;
        
    }
};