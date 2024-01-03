class Solution {
public:

    
    int numberOfBeams(vector<string>& bank) {
      int ans=0,curr=0;

        for(int i=0;i<bank.size();i++){
            
            int next=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')next++;
              }
          if(next>0){
              ans+=(curr*next);
              curr=next;
          }
        }
        
        return ans;
    }
};