class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int minbuy=prices[0];
        for(int &sell: prices){
            maxP=max(maxP, sell-minbuy);
            minbuy=min(minbuy,sell);
        }
        return maxP;
    }
};
