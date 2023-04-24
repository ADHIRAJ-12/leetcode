class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> maxi;
        for(auto i:stones)maxi.push(i);
        
        while(maxi.size()>1){
        int a=maxi.top();
        maxi.pop();
        int b=maxi.top();
        maxi.pop();
        if(a!=b)maxi.push(a-b);
        if(a==b)maxi.push(0);
        }
        return maxi.top();
    
    }
};