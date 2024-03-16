vector<int> Solution::getRow(int k)
{
    vector<int> ans;
    int i = 1;
    ans.push_back(1);
    if (k == 0)
        return ans;
    int prev = 1;
    while (i < k)
    {
        // mandatory to do multiply first and then divide
        // As only multiplication ensures the perfect divison later
        int curr = (prev * (k - i + 1)) / i;
        ans.push_back(curr);
        prev = curr;
        i++;
    }
    ans.push_back(1);
    return ans;
}
