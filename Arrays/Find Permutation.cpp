vector<int> Solution::findPerm(const string A, int B)
{
  int small = 1, large = B;
  vector<int> ans;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] == 'I')
    {
      ans.push_back(small);
      small++;
    }
    else
    {
      ans.push_back(large);
      large--;
    }
  }
  ans.push_back(small);
  return ans;
}
