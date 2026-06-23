class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto [num,f] : mp){
            bucket[f].push_back(num);
        }
        vector<int> res;
        for(int i = bucket.size()-1; i>0; i--){
            for(int num : bucket[i]){
                res.push_back(num);
                k--;
            }
            if(k==0){
                return res;
            }
        }
    }
};
