
// Given a string s, return the longest palindromic substring in s.
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        if (n==1)
            return s;
        string ans;
        for (int i=n-1;i>-1;i--){
            for (int j=i;j<n;j++){
                // Base Case P(i,i)
                if (i==j)
                    dp[i][j]=s[i]==s[i];
                // 2 Length substring.
                else if (j==i+1)
                    dp[i][j]=s[i]==s[j];
                else
                    dp[i][j]=dp[i+1][j-1]&&s[i]==s[j];
                if (dp[i][j]&&ans.size()<j-i+1)
                    ans = s.substr(i,j-i+1);
            }
        }
        return ans;
    }
};