vector<int> Solution::nextPermutation(vector<int> &arr)
{
  int n = arr.size();
  int i = n - 1, breakPoint = -1;
  // find an element which is not in increasing order
  while (i > 0)
  {
    if (arr[i - 1] < arr[i])
    {
      breakPoint = i - 1;
      break;
    }
    i--;
  }
  // if breakPoint == -1
  if (breakPoint == -1)
  {
    sort(arr.begin(), arr.end());
    return arr;
  }
  i = n - 1;
  // find element which is just bigger than the breakPoint element
  while (i > breakPoint)
  {
    if (arr[i] > arr[breakPoint])
    {
      swap(arr[i], arr[breakPoint]);
      break;
    }
    i--;
  }
  // sort remaining part after breakPoint to be the minimum
  sort(arr.begin() + breakPoint + 1, arr.end());
  return arr;
}
