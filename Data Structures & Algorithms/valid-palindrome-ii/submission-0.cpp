#include <cctype>
class Solution {
public:
    bool isPal(const string &s, int low, int high){
        while(low<high){
            if(s[low] != s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l] != s[r]){
                return isPal(s,l+1,r) || isPal(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};