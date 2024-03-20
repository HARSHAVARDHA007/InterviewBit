int Solution::repeatedNumber(const vector<int> &arr)
{
  int slow = arr[0], fast = arr[arr[0]];
  while (slow != fast)
  {
    slow = arr[slow];
    fast = arr[arr[fast]];
  }
  fast = 0;
  while (slow != fast)
  {
    slow = arr[slow];
    fast = arr[fast];
  }
  return fast;
}
