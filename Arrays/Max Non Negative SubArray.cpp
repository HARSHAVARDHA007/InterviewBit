vector<int> Solution::maxset(vector<int> &arr)
{
  long long int len = arr.size(), i = 0, j = 0, currMax = 0, finalMax = 0, finalLength = 0, flag = 0;
  vector<int> ans;
  pair<int, int> range;
  while (j < len)
  {
    // seen a -ve number
    if (arr[j] < 0)
    {
      if (currMax > finalMax || (currMax == finalMax && finalLength < (j - i)))
      {
        finalMax = currMax;
        finalLength = j - i;
        range = {i, j - 1};
      }
      i = j + 1;
      currMax = 0;
    }
    else
    {
      currMax += arr[j];
      flag = 1;
    }
    j++;
  }
  if (currMax > finalMax || (currMax == finalMax && finalLength < (j - i)))
  {
    range = {i, j - 1};
  }
  if (finalMax >= 0 && flag)
  {
    for (int i = range.first; i <= range.second; i++)
    {
      ans.push_back(arr[i]);
    }
  }
  return ans;
}
