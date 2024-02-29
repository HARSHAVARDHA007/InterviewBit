vector<int> Solution::findOccurences(vector<int> &arr)
{
  map<int, int> mp;
  for (auto ele : arr)
  {
    mp[ele]++;
  }
  vector<int> ans;
  for (auto ele : mp)
  {
    ans.push_back(ele.second);
  }
  return ans;
}
