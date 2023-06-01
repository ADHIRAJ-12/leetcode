class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        int count=0;
        
        pq.push(a);
        pq.push(b);
        pq.push(c);

        while(pq.top()>0){
        int m;
            if(pq.top()>0){
                m=pq.top();
                pq.pop();
            }
            int n;
            if(pq.top()>0){
                n=pq.top();
                pq.pop();
            }
            else break;
            
            pq.push(m-1);
            pq.push(n-1);
            count++;

            
        }
        return count;
        
        
    }
    
};