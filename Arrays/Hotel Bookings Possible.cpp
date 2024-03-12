bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
  vector<pair<int, int>> times;
  for (int i = 0; i < arrive.size(); i++)
  {
    times.push_back({arrive[i], depart[i]});
  }
  sort(times.begin(), times.end());
  multiset<int> q;
  int i = 0;
  while (i < arrive.size())
  {
    // get the current depart and arrive pair
    auto curr = times[i];
    int currDepart = curr.second;
    int currArrival = curr.first;
    // Clear all the rooms which are vacated from the queue before alloting to curr user
    auto itr = q.begin();
    while (q.begin() != q.end() && *q.begin() < currArrival)
    {
      q.erase(q.begin());
      K++;
    }
    // allot the room to the user
    q.insert(currDepart);
    K--;
    if (K < 0)
    {
      return 0;
    }
    i++;
  }
  return 1;
}
// o(nlogn)
// space o(n);

// --------------- best solution
// club the arrival times and depart times into same array and sort
// o(2n * log(2n));
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    assert(K>0 && K<=1000000);
    for(int a:arrive)
        assert(a>=0 && a<=1e8);
    for(int a:depart)
        assert(a>=0 && a<=1e8);
    for(int i=0;i<arrive.size();i++)
        assert(arrive[i]<=depart[i]);
    if(K == 0)
            return false;

    int N = arrive.size();
    assert(N>=1 && N<=1e6);
    vector<pair<int, int> > vec;
    for(int i = 0; i < N; ++i) {
        vec.push_back(make_pair(arrive[i], 0));
        vec.push_back(make_pair(depart[i], 1));
    }
     
    sort(vec.begin(), vec.end());
    
    int curActive = 0; // rooms booked currently
    int maxAns = 0; // max rooms used at a time
    for (int i = 0; i < vec.size(); i++) {
       if (vec[i].second == 0) { // arrival
           curActive++;
           maxAns = max(maxAns, curActive);
        } else { // Depart
            curActive--;
        }
    } 
    if (K >= maxAns) return true;
    return false;
}
