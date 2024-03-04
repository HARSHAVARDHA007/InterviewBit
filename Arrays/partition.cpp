int Solution::solve(int n, vector<int> &arr)
{
  int target_sum = 0;
  for (int i = 0; i < n; i++)
  {
    target_sum += arr[i];
  }
  if (target_sum % 3 != 0)
    return 0;
  target_sum = target_sum / 3;
  vector<int> suffix(n, 0);
  int sum = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    sum += arr[i];
    if (sum == target_sum)
      suffix[i] = 1;
  }
  int total_count = 0, prefix_sum = 0;
  for (int i = 0; i < n; i++)
  {
    prefix_sum += arr[i];
    if (prefix_sum == target_sum)
    {
      for (int j = i + 2; j < n; j++)
      {
        if (suffix[j] == 1)
          total_count++;
      }
    }
  }
  return total_count;
}
