class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        
        int sum1=0,sum2=0;
    
        for(int i=0;i<player1.size();i++){
            if(i>=1 and player1[i-1]>=10) sum1+=2*player1[i];  
            else if(i>=2 and (player1[i-1]>=10 or player1[i-2]>=10)) sum1+=2*player1[i]; 
            else sum1+=player1[i];  
        }
        
        for(int i=0;i<player2.size();i++){
           if(i>=1 and player2[i-1]>=10) sum2+=2*player2[i];
           else if(i>=2 and (player2[i-1]>=10 or player2[i-2]>=10)) sum2+=2*player2[i];
           else sum2+=player2[i];
        }
        
    if(sum1>sum2) return 1;
    else if(sum2>sum1) return 2;
    else return 0;
        
    }
};