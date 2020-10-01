class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int loc, glo;
    loc = glo = 0;
    for (unsigned int i=1; i<prices.size(); i++) {
        loc = max(loc+prices[i]-prices[i-1], 0);
        glo = max(glo, loc);
    }
    return glo;
}
};




