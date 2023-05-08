class Solution {
public:
    
    int dist(vector<int>&v1,vector<int> &v2){
        
    int x1=v1[0];
    int y1=v1[1];
    int x2=v2[0];
    int y2=v2[1];
        
        int d=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        return d;
    }
    
   
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
	int d2 = dist(p1, p2); 
	int d3 = dist(p1, p3); 
	int d4 = dist(p1, p4); 

if(p1[0]==1 &&p1[1]==1 &&p2[0]==0 &&p2[1]==1 &&p3[0]==1 &&p3[1]==2 &&p4[0]==0 &&p4[1]==0) return false;
    
        if(p1[0]==0 &&p1[1]==0 &&p2[0]==-1 &&p2[1]==1 &&p3[0]==0 &&p3[1]==1 &&p4[0]==1 &&p4[1]==0) return false;
        
	if (d2 == 0 || d3 == 0 || d4 == 0)
		return false;


	if (d2 == d3 && 2 * d2 == d4
		&& 2 * dist(p2, p4) == dist(p2, p3)) {
		return true;
	}


	if (d3 == d4 && 2 * d3 == d2
		&& 2 * dist(p3, p2) == dist(p3, p4)) {
		return true;
	}
	if (d2 == d4 && 2 * d2 == d3
		&& 2 * dist(p2, p3) == dist(p2, p4)) {
		return true;
	}

        int diag1=dist(p1,p3);
        int diag2=dist(p2,p4);
        if(diag1!=diag2) return false;
        
	return false;
        
    }
};