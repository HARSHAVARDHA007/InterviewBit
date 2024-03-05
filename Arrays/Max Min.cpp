int Solution::solve(vector<int> &arr) {
    int maxi=INT_MIN, mini=INT_MAX;
    for(int i=0; i<arr.size(); i++) {
        maxi = max(arr[i],maxi);
        mini = min(arr[i],mini);
    }
    return maxi+mini;
}
