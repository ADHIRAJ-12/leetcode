class Solution {
public:
    int maximumGroups(vector<int>& grades) {
       
        sort(grades.begin(),grades.end());
        set<int> s;
        int cnt=0,sz=1,temp=0;
        for(int i=0;i<grades.size();i++){
            temp+=grades[i];
            cnt++;
            if(cnt==sz){
                s.insert(temp);
                sz++;
                cnt=0;
                temp=0;
            }
        }
        return s.size();
    }
};