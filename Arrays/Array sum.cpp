vector<int> Solution::addArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 && j >= 0)
    {
        int curr = a[i] + b[j] + carry;
        if (curr < 10)
        {
            ans.push_back(curr);
            carry = 0;
        }
        else
        {
            ans.push_back(curr % 10);
            carry = curr / 10;
        }
        i--;
        j--;
    }
    // first number is done
    while (j >= 0)
    {
        int curr = b[j] + carry;
        if (curr < 10)
        {
            ans.push_back(curr);
            carry = 0;
        }
        else
        {
            ans.push_back(curr % 10);
            carry = curr / 10;
        }
        j--;
    }
    // second number is done
    while (i >= 0)
    {
        int curr = a[i] + carry;
        if (curr < 10)
        {
            ans.push_back(curr);
            carry = 0;
        }
        else
        {
            ans.push_back(curr % 10);
            carry = curr / 10;
        }
        i--;
    }
    if (carry)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
