struct Node{
    
    Node* links[2];
    
    bool containsKey(int ind){
        return (links[ind]!=NULL);
    }
    
    void put(int ind,Node* node){
        links[ind]=node;
    }
    Node* get(int ind){
        return links[ind];
    }

};

class Trie{
    
    private: Node* root;
    public:
    
    //constructor
    Trie(){
        root=new Node();
    }
    
    void insert(int num){
        
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
                node=node->get(bit);
        }    
    }
    
    public:
    int findMax(int num){
        
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(!bit)){
                maxNum=maxNum | (1<<i);
                node=node->get(!bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        //make a offline querirs vector holding <numLessThanInArray<numToXorWith,index>>
        //sort aacc to the numLessThanInArray
        //now push elemnet of arr in trie one by one acc to queries
        // get the max xor for the query by calling node->get()function
        //put the max value obtained in ans vector acc to index
        
        int n=nums.size();
        int m=queries.size();
        vector<int>ans(m,0);
        vector<pair<int,pair<int,int>>>oq;

        for(int i=0;i<m;i++){
            int x=queries[i][0];
            int maxi=queries[i][1];
            int ind=i;
            oq.push_back({maxi,{x,ind}});
        }
        sort(oq.begin(),oq.end());
        sort(nums.begin(),nums.end());
        
        int ind=0;
        Trie trie;
        
        for(auto &i:oq){
            
            while(ind<n && nums[ind]<=i.first){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind!=0)ans[i.second.second]=trie.findMax(i.second.first);
            else ans[i.second.second]=-1;
            
        }
        return ans;
        
        
        
    }
};