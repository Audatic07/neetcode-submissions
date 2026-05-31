class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0,l=0;
        unordered_set<char> window;
        for(int r=0; r<s.size(); r++){
            while(window.count(s[r])){
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            res=max(res,r-l+1);
        }
        return res;
    }
};
