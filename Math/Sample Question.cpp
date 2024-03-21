int Solution::solve(int A, int B)
{
  int num = 10000000;
  int ans = ((A % num) + (B % num)) % num;
  return ans;
}
