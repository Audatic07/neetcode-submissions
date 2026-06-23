class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string str : strs){
            string key="";
            vector<int>freq(26,0);
            for(char c : str){
                freq[c-'a']++;
            }
            for(int f : freq){
                key=key+'#'+to_string(f);
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};
