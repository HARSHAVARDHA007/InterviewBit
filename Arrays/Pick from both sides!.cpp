int Solution::solve(vector<int> &arr, int B)
{
  int len = arr.size();
  vector<int> preSum(len);
  vector<int> postSum(len);
  preSum[0] = arr[0];
  postSum[0] = arr[len - 1];
  for (int i = 1, j = len - 2; i < len && j >= 0; i++, j--)
  {
    preSum[i] = preSum[i - 1] + arr[i];
    postSum[i] = postSum[i - 1] + arr[j];
  }
  int ans = max(preSum[B - 1], postSum[B - 1]);
  for (int i = 0; i < B - 1; i++)
  {
    ans = max({ans, preSum[i] + postSum[B - i - 2]});
  }
  return ans;
}
