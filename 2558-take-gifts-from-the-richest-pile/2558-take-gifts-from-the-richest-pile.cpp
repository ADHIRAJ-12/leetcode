class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
     
        int n=gifts.size();
        long long result=0;
        
        //using priority queue for storing all the gifts
        priority_queue<long long>myqueue;
        
        //push all the gifts in priority queue 
        for(auto gift:gifts)myqueue.push(gift);
        
        //loop k times& take out the top element and push its root in priority queue ,decrement k
        while(k){
            myqueue.push(sqrt(myqueue.top()));
            myqueue.pop();
            k--;
        }
        
        //traverse priority queue untill empty and add the top element to ans;
        
        while(!myqueue.empty()){
            result+=myqueue.top();
            myqueue.pop();
        }
        return result;
        
    }
};