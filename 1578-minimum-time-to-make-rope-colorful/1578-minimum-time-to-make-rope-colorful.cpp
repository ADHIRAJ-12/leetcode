class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0,curr=0;
        
        for(int next=1;next<colors.length();next++){
        
            //same coloe but 1st balloon has less time
            if(colors[next]==colors[curr] && neededTime[next]>neededTime[curr]){
                ans+=neededTime[curr];
                curr=next;
            } 
            
            //same color but 2nd balloon has less time
        else if(colors[next]==colors[curr] && neededTime[next]<=neededTime[curr]){
                ans+=neededTime[next];
            } 
            //different color balloons
            else curr=next;    
        }
        return ans;
    }
};