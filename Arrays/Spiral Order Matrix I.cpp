#include<bits/stdc++.h>
using namespace std;
vector<int> Solution::spiralOrder(const vector<vector<int>> &a)
{

  int row = a.size();
  int col = a[0].size();
  vector<int> ans;
  int total_count = row * col;
  int curr_count = 0;
  pair<int, int> tl, tr, bl, br;
  tl = {0, 0};
  tr = {0, col - 1};
  bl = {row - 1, 0};
  br = {row - 1, col - 1};
  while (curr_count < total_count)
  {
    for (int i = tl.second; i <= tr.second; i++)
    {
      ans.push_back(a[tl.first][i]);
      curr_count++;
    }
    if (curr_count == total_count)
      break;
    tl.first++;
    tr.first++;
    for (int i = tr.first; i <= br.first; i++)
    {
      ans.push_back(a[i][tr.second]);
      curr_count++;
    }
    if (curr_count == total_count)
      break;
    br.second--;
    tr.second--;
    for (int i = br.second; i >= bl.second; i--)
    {
      ans.push_back(a[br.first][i]);
      curr_count++;
    }
    if (curr_count == total_count)
      break;
    br.first--;
    bl.first--;
    for (int i = bl.first; i >= tl.first; i--)
    {
      ans.push_back(a[i][bl.second]);
      curr_count++;
    }
    if (curr_count == total_count)
      break;
    bl.second++;
    tl.second++;
  }
  return ans;
}
