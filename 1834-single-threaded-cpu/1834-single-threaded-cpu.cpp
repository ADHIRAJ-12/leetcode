class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n=tasks.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int time=0,i=0;
        for(int i=0;i<n;i++)tasks[i].push_back(i);
        //pushing index 
        
        sort(tasks.begin(),tasks.end());
        vector<int>ans;
        
        while(i<n ||pq.size()){
            
            if(pq.empty())time= max(time,tasks[i][0]);
        
            while(i<n && time>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
        
        pair<long ,long> p=pq.top();
        pq.pop();
        time+=p.first;
        ans.push_back(p.second);
    }     
        return ans;
    }
};