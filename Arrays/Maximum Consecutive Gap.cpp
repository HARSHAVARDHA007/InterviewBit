int Solution::maximumGap(const vector<int> &arr)
{
  int n = arr.size();
  if (n < 2)
    return 0;
  int max_ele = INT_MIN, min_ele = INT_MAX;
  for (auto ele : arr)
  {
    max_ele = max(max_ele, ele);
    min_ele = min(min_ele, ele);
  }
  double gap = ((max_ele - min_ele) * 1.0) / (n - 1);
  if (gap < 1.0)
    gap = 1.0;
  vector<pair<int, int>> buckets(n, {INT_MAX, INT_MIN});
  for (auto ele : arr)
  {
    int pos = (ele - min_ele) / gap;
    buckets[pos].first = min(buckets[pos].first, ele);
    buckets[pos].second = max(buckets[pos].second, ele);
  }
  int prev_max = buckets[0].second, ans = 0;
  for (int i = 1; i < n; i++)
  {
    if (buckets[i].first == INT_MAX)
      continue;
    ans = max(buckets[i].first - prev_max, ans);
    prev_max = buckets[i].second;
  }
  return ans;
}
