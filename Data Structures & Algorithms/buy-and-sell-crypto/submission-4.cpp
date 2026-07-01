class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy=prices[0];
        int maxp=0;
        for(int sell: prices){
            maxp=max(maxp,sell-minbuy);
            minbuy=min(sell,minbuy);
        }
        return maxp;
    }
};
