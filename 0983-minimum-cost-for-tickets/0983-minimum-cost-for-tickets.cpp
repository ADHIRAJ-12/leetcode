class Solution {
public:
    
// int solveTab(vector<int> &days, vector<int> &cost){
//     int n=days.size();
//     vector<int>dp(n+1,INT_MAX);
//     dp[n]=0;
    
//     for(int k=n-1;k>=0;k--){
//          int option1=cost[0]+dp[k+1];
//     int i;
//     //7 days pass
//     for(i=k;i<n && days[i]<days[k]+7;i++);
    
//     int option2=cost[1]+dp[i];
    
//     //30 days
//     for(i=k;i<n && days[i]<days[k]+30;i++);
    
//     int option3=cost[2]+dp[i];
    
//     dp[k]= min(option1,min(option2,option3));
//     }
//   return dp[0];
// }



    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        // return solveTab(days,costs);
        int ans=0;
        queue<pair<int,int>> month;
        queue<pair<int,int>>week;
    
        for(int day:days){ 
        //remove expire days
        while(!month.empty() && month.front().first+30<=day)
            month.pop();
        
         while(!week.empty()&& week.front().first+7<=day)
            week.pop();
        
        //add cost of ccurrent days
        week.push(make_pair(day,ans+costs[1]));
        month.push(make_pair(day,ans+costs[2]));
        
        //update ans;
            
        ans=min(ans+costs[0],min(week.front().second,month.front().second));
    }
    
    
    return ans; 
    

    }
};