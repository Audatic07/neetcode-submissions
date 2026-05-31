class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(const string &x : strs){
            encoded+=to_string(x.size())+"#"+x;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i,j-i));
            j++;
            res.push_back(s.substr(j,len));
            i=j+len;
        }
        return res;

    }
};
