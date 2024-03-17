vector<vector<int>> Solution::generateMatrix(int n)
{

    vector<vector<int>> matrix(n, vector<int>(n, 1));
    int val = 1;
    int rbegin = 0, rend = n - 1, cbegin = 0, cend = n - 1;
    while (val <= n * n)
    {
        // top left -> row
        for (int i = cbegin; i <= cend; i++)
        {
            matrix[rbegin][i] = val;
            val++;
        }
        rbegin++;
        // right top -> bottom
        for (int i = rbegin; i <= rend; i++)
        {
            matrix[i][cend] = val;
            val++;
        }
        cend--;
        // bottom right -> left
        for (int i = cend; i >= cbegin; i--)
        {
            matrix[rend][i] = val;
            val++;
        }
        rend--;
        // left bottom -> top
        for (int i = rend; i >= rbegin; i--)
        {
            matrix[i][cbegin] = val;
            val++;
        }
        cbegin++;
    }
    return matrix;
}
