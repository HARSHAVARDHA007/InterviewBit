int Solution::solve(vector<int> &arr)
{
  int n = arr.size();
  vector<int> evenSum(n), oddSum(n);
  if ((n - 1) % 2 == 0)
  {
    evenSum[n - 1] = arr[n - 1];
    oddSum[n - 1] = 0;
  }
  else
  {
    evenSum[n - 1] = 0;
    oddSum[n - 1] = arr[n - 1];
  }
  // even place values and odd place value include current element
  for (int i = n - 2; i >= 0; i--)
  {
    evenSum[i] = evenSum[i + 1];
    oddSum[i] = oddSum[i + 1];
    if (i % 2 == 0)
    {
      evenSum[i] = evenSum[i] + arr[i];
    }
    else
    {
      oddSum[i] = oddSum[i] + arr[i];
    }
  }
  int evenSumTillNow = 0, oddSumTillNow = 0, count = 0;
  // remove curr element every time
  for (int i = 0; i < n; i++)
  {
    int curr_ele = arr[i];
    if (i != n - 1 && (evenSumTillNow + oddSum[i + 1]) == (oddSumTillNow + evenSum[i + 1]))
    {
      count++;
    }
    else if (i == n - 1 && evenSumTillNow == oddSumTillNow)
    {
      count++;
    }
    if (i % 2 == 0)
    {
      evenSumTillNow += arr[i];
    }
    else
    {
      oddSumTillNow += arr[i];
    }
  }
  return count;
}
