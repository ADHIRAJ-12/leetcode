class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      
       sort(costs.begin(), costs.end());
        int index=0;
        for(index=0; index<costs.size(); index++){
            if(coins < costs[index]){
                break;
            }
            else
                coins -= costs[index];
        }
        return index;
    }
};