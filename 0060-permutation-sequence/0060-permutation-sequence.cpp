class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial=1;
        vector<int>numbers;
        
        for(int i=1;i<n;i++){
            factorial=factorial*i;
            numbers.push_back(i);
        }
            numbers.push_back(n);
        //eg n=4  now numbers array will be [1,2,3,4] & factorial 3 will be present to divide groups 
        
        string ans="";
        k=k-1;  //0 based indexing
        
        while(true){
            ans+=to_string(numbers[k/factorial]);           // 16/6=2
             numbers.erase(numbers.begin()+k/factorial);   
            if(numbers.size()==0)break;                   //all taken
            k=k%factorial;                                //16%6->4
            factorial=factorial/numbers.size();          //!3 ->!2
        }
        return ans;
        
    }
};