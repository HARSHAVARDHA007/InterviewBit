int Solution::repeatedNumber(const vector<int> &arr)
{
  int n = arr.size();
  if (n <= 2)
    return arr[0];
  int ele_1 = INT_MAX, ele_2 = INT_MAX, count_1 = 0, count_2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == ele_1)
      count_1++;
    else if (arr[i] == ele_2)
      count_2++;
    else if (count_1 == 0)
    {
      count_1++;
      ele_1 = arr[i];
    }
    else if (count_2 == 0)
    {
      count_2++;
      ele_2 = arr[i];
    }
    else
    {
      count_1--;
      count_2--;
    }
  }
  // 2 potential answers are ele_1 and ele_2
  count_1 = 0;
  count_2 = 0;
  for (auto ele : arr)
  {
    if (ele == ele_1)
      count_1++;
    if (ele == ele_2)
      count_2++;
  }
  if (count_1 > (n / 3))
    return ele_1;
  if (count_2 > (n / 3))
    return ele_2;
  return -1;
}
