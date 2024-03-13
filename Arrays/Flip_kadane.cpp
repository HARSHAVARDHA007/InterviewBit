vector<int> Solution::flip(string A)
{
  int len = A.size();
  vector<int> arr(len);
  for (int i = 0; i < len; i++)
  {
    // replace 0 with 1 and 1 with -1
    arr[i] = A[i] == '0' ? 1 : -1;
  }
  // apply kadane's algo
  pair<int, int> ans = {INT_MAX, INT_MAX};
  int bestSoFar = 0, bestEndHere = 0;
  int l = 0;
  for (int i = 0; i < len; i++)
  {
    bestEndHere = max(arr[i], bestEndHere + arr[i]);
    // if best taking till current goes below zero discard this subarray
    if (bestEndHere < 0)
    {
      l = i + 1;
      bestEndHere = 0;
    }
    // update bestSoFar
    if (bestSoFar < bestEndHere)
    {
      bestSoFar = bestEndHere;
      ans.first = l;
      ans.second = i;
    }
  }
  // If not a single 0 is present
  if (ans.first == INT_MAX)
    return vector<int>();

  vector<int> ret_ans;
  ret_ans.push_back(ans.first + 1);
  ret_ans.push_back(ans.second + 1);
  return ret_ans;
}
