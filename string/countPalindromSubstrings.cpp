
// Given a string s, return the number of palindromic substrings in it.

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int dp[n][n];
        if (n==1)
            return 1;
        int count=0;
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
                if (dp[i][j])
                    count++;
            }
        } 
        return count;
    }
};