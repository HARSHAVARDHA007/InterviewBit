vector<int> Solution::flip(string arr)
{
  int len = arr.length();
  vector<int> prefix(len, 0);
  vector<int> sufix(len, 0);
  int left_index, right_index, global_left = 0, global_right = 0, leftSum = 0, rightSum = 0, flag = 0;
  for (int i = 0, j = len - 1; i < len, j >= 0; i++, j--)
  {
    // left to right
    // if we have less zeros than 1's i till now , we don't need it
    // Its better to start new
    if (arr[i] == '1' && leftSum > 0)
    {
      leftSum--;
      prefix[i] = leftSum;
    }
    else if (arr[i] == '0')
    {
      // we have atleast 1 zero
      flag = 1;
      leftSum++;
      prefix[i] = leftSum;
    }
    // For lexographical we have to the left one as it will be the first from the left
    if (leftSum > global_left)
    {
      global_left = leftSum;
      // left index will at the end of the best till now from left to right.
      left_index = i;
    }
    // right to left
    if (arr[j] == '1' && rightSum > 0)
    {
      rightSum--;
      sufix[j] = rightSum;
    }
    else if (arr[j] == '0')
    {
      rightSum++;
      sufix[j] = rightSum;
    }
    if (rightSum >= global_right)
    {
      global_right = rightSum;
      // right index will be at the end of the best till now from right to left
      // which is the start of the subarray from left to right
      right_index = j;
    }
  }
  vector<int> ans;
  if (flag)
  {
    ans.push_back(right_index + 1);
    ans.push_back(left_index + 1);
  }
  return ans;
}
