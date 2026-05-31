class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        int i=0;
        while(s[i+1] !='\0'){
            sum += abs(s[i]-s[i+1]);
            i++;
        }
        return sum;
        
    }
};