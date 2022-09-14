class Solution {
public:
    //when canBuy == 1 we buy the stock 
    int helper(vector<int>& prices,int ind, int canBuy,vector<vector<int>>& dp) {
        //if you have reached the end of array return 0 profit
        if(ind==prices.size())
            return 0;
        //if already have the profit value return that
        if(dp[ind][canBuy] != -1)
            return dp[ind][canBuy];
        int profit;
        //if not already holding a stock
        if(canBuy) 
            profit = max(
                //we either buy the current stock
                (-prices[ind]+helper(prices,ind+1,0,dp))
                //or move forward without buying
                ,(helper(prices,ind+1,1,dp))
            );
        else
            profit = max(
                //either sell the current stock and get +prices[ind] profit
                prices[ind]+helper(prices,ind+1,1,dp),
                //or move forward without selling it
                helper(prices,ind+1,0,dp)
            );
        dp[ind][canBuy] = profit;
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        //storing the profit at each day (for both selling and buying)
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        //dp[ind][0] is for selling and dp[ind][1] stores profit if we buy the stock
        return helper(prices,0,1,dp);
    }
};