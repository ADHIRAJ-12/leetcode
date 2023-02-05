class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
         int n=words.size(),i=0;
         int m=queries.size();
        vector<int>temp1(n),temp2(n),ans(m,0);
        
        //traverse words
        for(auto word: words){
            int end=word.size()-1;
            //if a word starting and ending with vowel is found store it in ans
            if (( word[0]=='a' or  word[0]=='e' or  word[0]=='i' or  word[0]=='o' or  word[0]=='u')
                and ( word[end]=='a' or  word[end]=='e' or  word[end]=='i' or  word[end]=='o' or  word[end]=='u')){
                temp1[i]=1;
                i++;
            }
            else{ temp1[i]=0;
                i++;
                }
        }
        
        temp2[0]=temp1[0];
        for(int i=1; i<n; i++) temp2[i]=temp2[i-1]+temp1[i];
        
        for(int i=0; i<m; i++){
            int startInd=queries[i][0];
            int endInd=queries[i][1];
            
            if(startInd==0) ans[i]=temp2[endInd];
            else ans[i]=temp2[endInd]-temp2[startInd-1];
        }
        return ans;

        
    }
};