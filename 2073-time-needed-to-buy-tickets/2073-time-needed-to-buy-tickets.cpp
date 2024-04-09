class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
     queue<pair<int,int>>q;
     int time=0;

     for(int i=0;i<tickets.size();i++){
         q.push({tickets[i],i});
     }
        
        while(!q.empty()){
            
        pair<int,int>temp=q.front();
        q.pop();
        
          --temp.first;
          ++time;  
            
            if(temp.first==0 && temp.second==k) break;
            
            else if(temp.first!=0){
                q.push({temp.first,temp.second});
            }
         
        }
                    return time;

    }
};