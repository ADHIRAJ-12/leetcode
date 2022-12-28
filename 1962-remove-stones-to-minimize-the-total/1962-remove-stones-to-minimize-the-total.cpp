class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>pq;
        
        for(int i=0;i<piles.size();i++)pq.push(piles[i]);
        //push every element in array
        
        for(int i = 0; i<k; i++){
             if(pq.size() == 0) return 0; 
            //if all elements are removed
            
            int tp=pq.top();
            pq.pop();
            //take out top element
            
            
            //perform operation and push in pq again
           tp = (tp+1)/2;
            if(tp!=0)pq.push(tp);
        }
        
        //sum of all remaining elements
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};