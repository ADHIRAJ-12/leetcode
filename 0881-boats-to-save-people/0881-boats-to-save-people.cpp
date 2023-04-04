class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
     
        int n=people.size(),count=0;
        sort(people.begin(),people.end());
       
        int s=0,e=n-1;
        while(s<=e){
            int sum=people[s]+people[e];
            if(sum<=limit){
                count++;
                s++;
                e--; 
            }
            else {
                
            e--;
            count++;
                
            }
        }
        return count;
        
    }
};