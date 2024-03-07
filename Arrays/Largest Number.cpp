bool comp(string x, string y) {
    return x+y > y+x;
}
string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> arr;
    int flag =0;
    for(auto ele : A) {
        if(ele > 0) flag=1;
        arr.push_back(to_string(ele));
    }
    sort(arr.begin(),arr.end(),comp);
    string ans = "";
    for(auto ele : arr) {
        ans += ele;
    }
    return flag ? ans : "0";
}
