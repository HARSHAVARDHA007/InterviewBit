vector<int> Solution::solve(vector<int> &arr)
{
  int n = arr.size();
  int i = 0, j = n - 1;
  vector<int> ans(n);
  int x = n - 1;
  while (i <= j)
  {
    if (abs(arr[i]) >= abs(arr[j]))
    {
      ans[x] = arr[i] * arr[i];
      i++;
    }
    else
    {
      ans[x] = arr[j] * arr[j];
      j--;
    }
    x--;
  }
  return ans;
}
