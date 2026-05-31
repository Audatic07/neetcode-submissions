class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(const auto &[num,f] : mp){
            bucket[f].push_back(num);
        }
        vector<int> result;
        for(int i=bucket.size()-1; i>=0 && result.size() < k; i--){
            for(int num: bucket[i]){
                result.push_back(num);
                if(result.size() == k) break;
            }
        }
        return result;
        
    }
};
