class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();

        for(auto ch: operations){
            if(ch=="C")
            st.pop();

            else if(ch=="+"){
                int num2 = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                st.push(num1);
                st.push(num2);

                st.push(num1+num2);
            }

            else if(ch=="D"){
                st.push(2*st.top());
            }

            else{
                st.push(stoi(ch));
            }
        }

        int sum = 0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }

        return sum;
    }
};