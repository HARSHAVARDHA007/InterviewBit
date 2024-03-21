string Solution::findDigitsInBinary(int A)
{
  string ans;
  if (A == 0)
    return "0";
  while (A)
  {
    A % 2 == 0 ? ans += '0' : ans += '1';
    A = A / 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
