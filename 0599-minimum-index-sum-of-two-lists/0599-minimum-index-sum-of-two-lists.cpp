class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n=list1.size();
        int m=list2.size(); 
        vector<string>ans;
        int sum=1e8,index=-111;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(list1[i]==list2[j]){
                index=i+j;
                if(index<sum){
                    sum=index;
                    ans={list1[i]};
                }
                else if(index==sum)ans.push_back(list1[i]);
            } 
          }
        }
        return ans;
    }
};