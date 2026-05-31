class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0; i<operations.size(); i++){
            if(operations[i] == "+"){
                int a=st.top();
                st.pop();
                int sum=a+st.top();
                st.push(a);
                st.push(sum);
            }
            else if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                st.push(2*st.top());
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int res=0;
        int st_size=st.size();
        for(int i=0; i<st_size; i++){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};