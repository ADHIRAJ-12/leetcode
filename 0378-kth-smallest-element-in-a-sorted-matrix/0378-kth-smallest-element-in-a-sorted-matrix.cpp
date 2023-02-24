class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //using heaps
        
        priority_queue<int>pq;
        int size = matrix.size();
        
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                pq.push(matrix[i][j]);
                 
                if(pq.size()>k)  pq.pop();
            }
        }
       return pq.top();
    }
};

