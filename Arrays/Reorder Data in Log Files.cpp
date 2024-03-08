bool comp(string a, string b)
{
  // sort the letter strings after the identifier
  int pos1 = a.find('-');
  int pos2 = b.find('-');
  a = a.substr(pos1 + 1);
  b = b.substr(pos2 + 1);
  return a < b;
}
vector<string> Solution::reorderLogs(vector<string> &arr)
{
  vector<string> letterLogs;
  vector<string> numberLogs;
  for (auto log : arr)
  {
    // find the first character after the delimiter
    int pos = log.find('-');
    char ele = log[pos + 1];
    if (ele >= '0' && ele <= '9')
    {
      numberLogs.push_back(log);
    }
    else
    {
      letterLogs.push_back(log);
    }
  }
  // custom sorting
  sort(letterLogs.begin(), letterLogs.end(), comp);
  for (auto digiLog : numberLogs)
  {
    letterLogs.push_back(digiLog);
  }
  return letterLogs;
}
