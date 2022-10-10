
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock.  
// You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // int temp;
        // vector<int> dp(n,0);
        // for (int i=0;i<n;i++){
        //     for (int j=0;j<i;j++){
        //         if(prices[j]<prices[i]){
        //             temp = prices[i]-prices[j];
        //             // cout<<temp<<endl;
        //             // cout<<prices[j]<<" "<<prices[i-1]<<endl;
        //             // cout<<"ma "<<max(dp[j]+temp,dp[i-1])<<endl;
        //             dp[i] = max(dp[i],max(dp[j]+temp,dp[i-1]));
        //         }
        //         else
        //             dp[i] = dp[i-1];
        //     }
        // }
        // // int m=0;
        // // for (auto it:dp){
        // //     m = max(it,m);
        // // }
        // return dp[n-1];
        
        int profit=0;
        for (int i=0;i<prices.size()-1;i++){
            if (prices[i]<prices[i+1])
                profit += prices[i+1]-prices[i];
        }
        return profit;
    }
};