class FoodRatings {
    //map to store food ->cuisine->rating
    map<string, pair<string, int>> foodCusRat;
    //map to store cuisine->rating->food
    map<string, map<int,set<string>>> cusRatFood;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        //intialize each thing in map
        int n=foods.size();
         for(int i=0;i<n;i++){
            foodCusRat[foods[i]] = {cuisines[i], ratings[i]};
            cusRatFood[cuisines[i]][ratings[i]].insert(foods[i]);
         }

    }
    
    void changeRating(string food, int newRating) {
        //find string named food in 1st map
       auto currentFood = foodCusRat.find(food);
       //take out its cusine
        string cuisine = currentFood->second.first;
        //take out its rating
        int currentRating = currentFood->second.second;
        //change rating
        currentFood->second.second = newRating;

        //now  change in 2nd map.erase current food 
        cusRatFood[cuisine][currentRating].erase(food);

        if (cusRatFood[cuisine][currentRating].empty())
        //erase entry of current rating
            cusRatFood[cuisine].erase(currentRating);
        //enter new rating and insert food maping to it
        cusRatFood[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
       return *cusRatFood[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */