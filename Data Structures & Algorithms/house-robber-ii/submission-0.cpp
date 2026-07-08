class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return nums[0];
        int final = max(roblinear(nums,0,n-1),roblinear(nums,1,n));
        return final;
    }
    int roblinear(vector<int>&nums, int left, int right){
        int prev1=0;
        int prev2=0;
        for(int i=left; i<right; i++){
            int current = max(prev1, prev2+nums[i]);
            prev2=prev1;
            prev1=current;
        }
        return prev1;
    }
};
