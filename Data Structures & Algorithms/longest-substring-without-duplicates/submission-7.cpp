class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l=0;
        int best=0;
        for(int r=0; r<s.size(); r++){
            while(seen.contains(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            best=max(best,(int)seen.size());
        }
        return best;
    }
};
