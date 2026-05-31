class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> look;
        for(int x: nums){
            look.insert(x);
        }
        int ans=0;
        for(int x: nums){
            int count=1;
            if(!look.count(x-1)){
                int start=x;
                while(look.count(start+1)){
                    count++;
                    start++;
                }
                if(count>ans){
                    ans=count;
                }
            }
        }
        return ans;
    }
};
