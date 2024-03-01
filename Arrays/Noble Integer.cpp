int Solution::solve(vector<int> &arr)
{
  int total_sum = arr.size(), curr_count = 0;
  map<int, int> mp;
  for (auto ele : arr)
  {
    mp[ele]++;
  }
  for (auto ele : mp)
  {
    curr_count += ele.second;
    if (ele.first == total_sum - curr_count)
    {
      return 1;
    }
  }
  return -1;
}
