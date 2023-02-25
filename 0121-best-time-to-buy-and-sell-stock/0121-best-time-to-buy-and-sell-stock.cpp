
class Solution {
public:
//     int maxProfit(vector<int>& prices) {
//         int least = INT_MAX;
//         int profit = 0;
//         int profitIFSoldToday = 0;
        
//         for(int i = 0; i < prices.size(); i++){
//             if(prices[i] <  least){
//                 least = prices[i];
//             }
//             profitIFSoldToday = prices[i] - least;
//             if(profit< profitIFSoldToday){
//                 profit = profitIFSoldToday;
//             }
//         }
//         return profit;
        
       
//     }
    int maxProfit(vector<int>& prices){
        
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            int diff=prices[i]-mini;
            profit=max(profit,diff);
            mini=min(mini,prices[i]);
        }
        return profit;
        
    }
};
        
        
