class Solution {
public:
    bool isPathCrossing(string str) {
        int x=0,y=0;
        set<pair<int,int>>s;
        s.insert({0,0});
        
        for(int i=0;i<str.length();i++){
            if(str[i]=='N')y++;
            if(str[i]=='S')y--;
            if(str[i]=='E')x++;
            if(str[i]=='W')x--;

        if(s.find({x,y})!=s.end())return true;
        s.insert({x,y});
        }
        return false;
    }
};