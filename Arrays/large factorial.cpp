void multiply(vector<int> &ans, int x)
{
  int value = 0;
  for (int i = 0; i < ans.size(); i++)
  {
    value = value + ans[i] * x;
    ans[i] = value % 10;
    value = value / 10;
  }
  while (value)
  {
    ans.push_back(value % 10);
    value = value / 10;
  }
}
string Solution::solve(int a)
{
  vector<int> ans;
  ans.push_back(1);
  for (int i = 2; i <= a; i++)
  {
    multiply(ans, i);
  }
  string fact = "";
  for (int i = ans.size() - 1; i >= 0; i--)
  {
    fact = fact + to_string(ans[i]);
  }
  return fact;
}
