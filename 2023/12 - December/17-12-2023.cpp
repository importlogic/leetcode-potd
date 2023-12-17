/*

Author : Manas Rawat
Date : 17/12/2023
Problem : Design a Food Rating System
Difficulty : Medium
Problem Link : https://leetcode.com/problems/design-a-food-rating-system/
Video Solution : https://youtu.be/z9HOFXzdoXE

*/


class FoodRatings {
public:
    map<string, map<int, set<string>>> cuisine_rating;
    map<string, string> food_type;
    map<string, int> food_rating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();    
        
        for(int i = 0; i < n; i++){
            food_type[foods[i]] = cuisines[i];
            cuisine_rating[cuisines[i]][ratings[i]].insert(foods[i]);
            food_rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_type[food];
        int oldRating = food_rating[food];
        
        cuisine_rating[cuisine][oldRating].erase(food);
        
        if(cuisine_rating[cuisine][oldRating].size() == 0)
            cuisine_rating[cuisine].erase(oldRating);
        
        food_rating[food] = newRating;
        
        cuisine_rating[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        set<string> food_list = (*cuisine_rating[cuisine].rbegin()).second;
        
        return *food_list.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */