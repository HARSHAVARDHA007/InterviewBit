#include <bits/stdc++.h>
using namespace std;

int Solution::maxSubArray(const vector<int> &arr)
{
  int len = arr.size();
  int ans = arr[0];
  int prev = arr[0];
  for (int i = 1; i < len; i++)
  {
    prev = max(arr[i], prev + arr[i]);
    ans = max(ans, prev);
  }
  return ans;
}
