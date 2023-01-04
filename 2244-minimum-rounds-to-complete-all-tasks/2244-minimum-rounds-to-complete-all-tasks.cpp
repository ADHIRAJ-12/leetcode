class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int>m;
        for(int i=0;i<tasks.size();i++)m[tasks[i]]++;
        int count=0;
        for(auto i:m){
            int num=i.second;
            if(num<2)return -1;
            count=count+num/3;
            num=num%3;
            if(num!=0)count++;
        }
        return count;
    }
};