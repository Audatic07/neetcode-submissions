class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> pairs;
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target-position[i])/speed[i];
            pairs.push_back({position[i],time});
        }
        sort(pairs.rbegin(), pairs.rend());
        stack<double> st;
        for(auto &[position, time] : pairs){
            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
