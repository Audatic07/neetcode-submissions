class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0; //money if we robbed the previous house
        int prev2=0; //money if we robbed the previous to previous house
        //at each house, we can only decide between robbing and not robbing
        //if we rob, then the previous house can't be robbed, only the prev2 one and the current one
        //so, we choose the max value, whether we get the prev house, or these two houses.
        //this is the DP, we get the best solution till this house, and move to next one
        int current;
        for(int i=0; i<nums.size(); i++){
            current = max(prev1, prev2+nums[i]);
            prev2=prev1;
            prev1=current;
        }
        return current;
    }
};
