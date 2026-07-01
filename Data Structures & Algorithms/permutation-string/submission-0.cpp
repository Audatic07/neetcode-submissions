class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        vector<int> s1C(26,0);
        vector<int> s2C(26,0);
        for(int i=0; i<s1.length(); i++){
            s1C[s1[i]-'a']++;
            s2C[s2[i]-'a']++;
        }
        int matches=0;
        for(int i=0; i<26; i++){
            if(s1C[i]==s2C[i]){
                matches++;
            }
        }
        int l=0;
        for(int r=s1.length(); r<s2.length(); r++){
            if(matches==26) return true;
            int idx = s2[r]-'a';
                s2C[idx]++;
                if(s1C[idx]==s2C[idx]) matches++;
                else if(s1C[idx]+1==s2C[idx]) matches--;
                idx=s2[l]-'a';
                s2C[idx]--;
                if(s1C[idx]==s2C[idx]) matches++;
                else if(s1C[idx]-1==s2C[idx]) matches--;
                l++;
            }
        return matches == 26;
    }
};
