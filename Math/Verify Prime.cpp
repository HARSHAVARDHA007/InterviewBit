int Solution::isPrime(int A)
{
  if (A <= 1)
    return 0;
  int divisor = ceil(sqrt(A));
  for (int i = 2; i <= divisor; i++)
  {
    if (i != A && A % i == 0)
      return 0;
  }
  return 1;
}
