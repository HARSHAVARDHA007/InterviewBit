vector<vector<int>> Solution::diagonal(vector<vector<int>> &A)
{
    int n = A.size();
    vector<vector<int>> ans;
    int row = 0;
    // first part
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        int y = row;
        vector<int> diagonal;
        while (y >= 0)
        {
            diagonal.push_back(A[x][y]);
            y--;
            x++;
        }
        row++;
        ans.push_back(diagonal);
    }
    // second part
    for (int i = 1; i < n; i++)
    {
        int x = i;
        int y = n - 1;
        vector<int> diagonal;
        while (y >= i)
        {
            diagonal.push_back(A[x][y]);
            y--;
            x++;
        }
        ans.push_back(diagonal);
    }
    return ans;
}
