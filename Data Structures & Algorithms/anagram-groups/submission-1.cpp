class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s :  strs){
            vector<int> freq(26,0); //frequency vector to keep up count of elements
            for(char i: s){
                freq[i-'a']++;
            }
            string key; //make a key to a signature of a set of anagrams
            for(int f: freq){
                key += "#" + to_string(f);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};
