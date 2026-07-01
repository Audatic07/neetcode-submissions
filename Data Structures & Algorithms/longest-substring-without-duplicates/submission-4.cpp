class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int l=0, res=0;
        for(int i=0; i<s.size(); i++){
            while(window.contains(s[i])){
                window.erase(s[l]);
                l++;
            }
            window.insert(s[i]);
            res=max(res,i-l+1);
        }
        return res;
    }
};
