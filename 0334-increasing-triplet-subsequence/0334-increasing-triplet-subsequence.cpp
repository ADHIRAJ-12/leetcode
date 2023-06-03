class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        
        //greedy approach
int first=INT_MAX,second=INT_MAX;
        
        for(auto i:nums){
            
            if(i<first) first=i;
            
            else if(i>first && i<second)second=i;
            
            else if(i>second )return true;
            
        }
        return false;
    }
};