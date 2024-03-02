#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int power)
{
  int len = arr.size();
  int i = 0;
  int ans = 0;
  while (i < len)
  {
    // To light the position at i there has to be atleast one light from range j to k
    int j = i + power - 1;
    int k = i - power + 1;
    if (j >= len)
      j = len - 1;
    if (k < 0)
      k = 0;
    int flag = 0;
    // Greedy approach start from the right most possible position
    for (int x = j; x >= k; x--)
    {
      if (arr[x] == 1)
      {
        ans++;
        flag = 1;
        // if you have lighten at position x then till x+power-1 position
        // all the positions are lighted because of this so i moves to next position
        // after the lighted position
        i = x + power - 1;
        break;
      }
    }
    i++;
    // if you don't find atleast one in the current range so it is impossible to light ith position
    if (!flag)
      return -1;
  }
  return ans;
}
