class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
     
        int ans=INT_MAX,n=words.size();
        vector<int>temp;
        bool flag =false;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                flag =true;
               temp.push_back(i);
            }
        }
        if(flag==false)return -1;
        
       for(int i=0;i<temp.size();i++){
           int diff=abs(temp[i]-startIndex);
           ans=min(ans,min(diff,n-diff));
       }
        return ans;
        
    }
};