vector<int> Solution::repeatedNumber(const vector<int> &arr)
{
  vector<int> ans;
  long long int len = arr.size();
  long long int sum_n = (len * (len + 1)) / 2;
  long long int square_n = (len * (len + 1) * (2 * len + 1)) / 6;
  for (int i = 0; i < len; i++)
  {
    sum_n = sum_n - (long long int)arr[i];
    square_n = square_n - (long long int)arr[i] * (long long int)arr[i];
  }
  // now sum_n has X-Y
  // square_n has X^2 - Y^2
  long long int missing = (square_n + (long long int)(sum_n * sum_n)) / (long long int)(2 * sum_n);
  long long int repeating = missing - sum_n;
  ans.push_back(repeating);
  ans.push_back(missing);
  return ans;
}
