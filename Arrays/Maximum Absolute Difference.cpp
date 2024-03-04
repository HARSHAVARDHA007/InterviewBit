#include <bits/stdc++.h>
using namespace std;
int Solution::maxArr(vector<int> &arr)
{
  int max_1 = INT_MIN, min_1 = INT_MAX, max_2 = INT_MIN, min_2 = INT_MAX;
  for (int i = 0; i < arr.size(); i++)
  {
    // arr[i] + i
    int x = arr[i] + i + 1;
    // arr[i] - i
    int y = arr[i] - i - 1;
    max_1 = max(x, max_1);
    min_1 = min(x, min_1);
    max_2 = max(y, max_2);
    min_2 = min(y, min_2);
  }
  return max(abs(max_1 - min_1), abs(max_2 - min_2));
}
