class Solution {
public:
    bool isValid(string s) {
        stack<char> track;
        for(auto ch : s) {

        if(ch=='{' || ch=='(' || ch=='[') {
            track.push(ch);
        }
        else {
            if(track.empty()) return false;

            if((track.top()=='(' && ch==')') ||
               (track.top()=='{' && ch=='}') ||
               (track.top()=='[' && ch==']')) {

                track.pop();
            }
            else {
                return false;
            }
        }
    }

    return track.empty();
    }
};
