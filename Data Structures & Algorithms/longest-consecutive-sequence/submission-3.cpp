class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>look;
        for(int x : nums){
            look.insert(x);
        }
        int res=0;
        for(int num : nums){
            if(!look.contains(num-1)){
                int start=num;
                int length=0;
                while(look.contains(start+length)){
                    length++;
                }
                res=max(length,res);
            }
        }
        return res;
    }
};
