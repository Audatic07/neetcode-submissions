class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto ch: operations){
            if(ch == "+"){
                int a=st.top();
                st.pop();
                int sum=a+st.top();
                st.push(a);
                st.push(sum);
            }
            else if(ch=="C"){
                st.pop();
            }
            else if(ch=="D"){
                st.push(2*st.top());
            }
            else{
                st.push(stoi(ch));
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};