class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int freq[26]={0};
        for(int i : s){
            freq[i-'a']++;
        }
        for(int i : t){
            freq[i-'a']--;
            if(freq[i-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
