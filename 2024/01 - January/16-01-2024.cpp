/*

Author : Manas Rawat
Date : 16/01/2024
Problem : Insert Delete GetRandom O(1)
Difficulty : Medium
Problem Link : https://leetcode.com/problems/insert-delete-getrandom-o1/description/
Video Solution : https://youtu.be/teTh40HoM60

*/


class RandomizedSet {
public:
    unordered_map<int, int> pos;
    vector<int> values;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(pos.find(val) != pos.end())
            return 0;

        pos[val] = values.size();
        values.push_back(val);

        return 1;    
    }
    
    bool remove(int val) {
        if(pos.find(val) == pos.end())
            return 0;

        int p1 = pos[val];
        int p2 = values.size() - 1;

        swap(values[p1], values[p2]);
        values.pop_back();

        pos[values[p1]] = p1;

        pos.erase(val);

        return 1;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */