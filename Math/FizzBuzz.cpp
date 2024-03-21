vector<string> Solution::fizzBuzz(int A)
{
  vector<string> ans;
  for (int ele = 1; ele <= A; ele++)
  {
    if (ele % 3 == 0 && ele % 5 == 0)
    {
      ans.push_back("FizzBuzz");
    }
    else if (ele % 3 == 0)
    {
      ans.push_back("Fizz");
    }
    else if (ele % 5 == 0)
    {
      ans.push_back("Buzz");
    }
    else
    {
      ans.push_back(to_string(ele));
    }
  }
  return ans;
}
