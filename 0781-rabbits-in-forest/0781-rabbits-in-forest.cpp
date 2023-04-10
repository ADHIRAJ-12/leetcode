class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<answers.size();i++){
            if(answers[i]==0) ans++;  //unique rabbit found
            else m[answers[i]]++;
            
        }
        
        for(auto i:m){
            ans+=(i.first+1)*ceil(((float)i.second/(i.first+1)));
        }
        
        return ans;
    }
};