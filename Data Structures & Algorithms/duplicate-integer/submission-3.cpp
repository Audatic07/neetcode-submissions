class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> has_occured;
        for(int x : nums){
            if(has_occured.count(x)){
                return true;
            }
            has_occured.insert(x);
        }
        return false;
    }
};