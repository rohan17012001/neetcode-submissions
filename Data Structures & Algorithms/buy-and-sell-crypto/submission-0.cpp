class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int i=0;
        int n=prices.size();
        for(int j=0; j<n; j++){
            if(prices[j]<prices[i]) i=j;
            else ans =max(ans, prices[j]-prices[i]);
        }
        return ans;
    }
};
