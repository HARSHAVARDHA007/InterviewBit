int Solution::solve(vector<vector<int>> &arr, int b)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // calculate dp sum
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            dp[i][j] = arr[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    // calculate the max sum
    int ans = INT_MIN;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            // if there is a possiible matrix
            if (i - b >= 0 && j - b >= 0)
            {
                int curr_sum = dp[i][j] - dp[i][j - b] - dp[i - b][j] + dp[i - b][j - b];
                ans = max(ans, curr_sum);
            }
        }
    }
    return ans;
}
