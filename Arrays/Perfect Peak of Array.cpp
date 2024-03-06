int Solution::perfectPeak(vector<int> &arr)
{
  int len = arr.size();
  vector<int> smallest(len);
  vector<int> largest(len);
  smallest[len - 1] = arr[len - 1];
  largest[0] = arr[0];
  for (int i = 1, j = len - 2; i < len - 1, j >= 0; i++, j--)
  {
    smallest[j] = min(smallest[j + 1], arr[j]);
    largest[i] = max(largest[i - 1], arr[i]);
  }
  for (int i = 1; i < len - 1; i++)
  {
    if (largest[i - 1] < arr[i] && smallest[i + 1] > arr[i])
      return 1;
  }
  return 0;
}
