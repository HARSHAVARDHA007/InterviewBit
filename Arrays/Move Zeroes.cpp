vector<int> Solution::solve(vector<int> &arr)
{
  int i = 0, j = 0, n = arr.size();
  while (j < n)
  {
    // Push non zero numbers into ith place
    // so that all non zero numbers will be in first places
    if (arr[j] != 0)
    {
      arr[i] = arr[j];
      i++;
    }
    j++;
  }
  // after that fill remaining all values with 0
  while (i < n)
  {
    arr[i] = 0;
    i++;
  }
  return arr;
}
