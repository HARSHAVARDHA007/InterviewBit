vector<int> k_row_pascal(int k)
{
    k = k - 1;
    vector<int> ans;
    ans.push_back(1);
    int prev = 1, i = 1;
    while (i < k)
    {
        int next = ((k - i + 1) * prev) / i;
        ans.push_back(next);
        prev = next;
        i++;
    }
    ans.push_back(1);
    return ans;
}
vector<vector<int>> Solution::solve(int A)
{
    vector<vector<int>> ans;
    if (A == 0)
        return ans;
    ans.push_back({1});
    for (int i = 2; i <= A; i++)
    {
        ans.push_back(k_row_pascal(i));
    }
    return ans;
}
