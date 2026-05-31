class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int k=nums.size()-1;
        while(1){
            if(nums[i]+nums[k]>target){
                k--;
            }
            else if(nums[i]+nums[k]<target){
                i++;
            }
            else{
                return {i+1,k+1};
            }
        }
    }
};
