vector<int> Solution::wave(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int i=0,j=1;
    while(j<n) {
        swap(arr[i],arr[j]);
        i = i+2;
        j = j+2;
    }
    return arr;
}
