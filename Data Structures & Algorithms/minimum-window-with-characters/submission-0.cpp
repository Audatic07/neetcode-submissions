class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char,int> countT, window;
        for(char c : t){
            countT[c]++;
        }
        int resLen = INT_MAX, l=0, have=0, need=countT.size(), res_start=-1;
        for(int r=0; r<s.size(); r++){
            window[s[r]]++;
            if(countT.contains(s[r]) && window[s[r]]==countT[s[r]]){
                have++;
            }
            while(have==need){
                if(r-l+1 < resLen){
                    resLen=r-l+1;
                    res_start=l;
                }
                window[s[l]]--;
                if(countT.contains(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res_start, resLen);
    }
};
