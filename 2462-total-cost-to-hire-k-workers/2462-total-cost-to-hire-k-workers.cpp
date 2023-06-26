class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        int n=costs.size(),c= 0,i=0,j=n-1;

        while(c<k){

            while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);

            int cost1 = pq1.size()>0?pq1.top():1e5+10;
            int cost2 = pq2.size()>0?pq2.top():1e5+10;

            if(cost1<=cost2){

               ans += cost1;
               pq1.pop();
            }
            else{

              ans += cost2;
              pq2.pop();
            }

            c++;
        }

        return ans;
    }
};