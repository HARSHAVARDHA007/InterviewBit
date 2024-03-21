vector<int> Solution::sieve(int A)
{
  bool prime[A + 1];
  fill_n(prime, A + 1, true);
  int maxLimit = ceil(sqrt(A));
  for (int i = 2; i <= maxLimit; i++)
  {
    if (prime[i])
    {

      // mark all the number which are multiples of i as non prime
      // Only have to deal with number greater than square of i
      // O(N*log(log(N)))
      // O(N) - space (can only use this algo for numbers less than space limit 10^6)
      for (int j = i * i; j <= A; j = j + i)
      {
        prime[j] = false;
      }
    }
  }
  vector<int> ans;
  for (int i = 2; i <= A; i++)
  {
    if (prime[i])
    {
      ans.push_back(i);
    }
  }
  return ans;
}
