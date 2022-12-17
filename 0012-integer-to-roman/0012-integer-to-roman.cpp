class Solution {
public:
    string intToRoman(int num) {
       
        string res="";
        int value[] ={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string roman[] ={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;

        while(num){
            if(num>=value[i]){
                num=num-value[i];
                res=res+roman[i];
            }
            else i--;
        }
        return res;

    }
};