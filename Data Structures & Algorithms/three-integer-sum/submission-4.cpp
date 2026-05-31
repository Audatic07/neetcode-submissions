class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=nums.size()-1;
            vector<int> ans;
            while(j<k){
                if(nums[j]+nums[k]<(-nums[i])){
                    j++;
                }
                else if(nums[j]+nums[k]>(-nums[i])){
                    k--;
                }
                else{
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j++]);
                    ans.push_back(nums[k--]);
                    res.push_back(ans);
                    ans.clear();
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};
