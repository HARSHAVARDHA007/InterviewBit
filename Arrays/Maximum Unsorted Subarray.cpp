vector<int> Solution::subUnsort(vector<int> &arr) {
    int n = arr.size();
    int s = -1, e = -1;
    // find index that is not sorted from left
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            s = i;
            break;
        }
    }
    if(s == -1) {
        // array is already sorted
        return {-1};
    }
    // Find index that is not sorted from right
    for(int i = n - 1; i > 0; i--) {
        if(arr[i] < arr[i - 1]) {
            e = i;
            break;
        }
    }
    // find min val and max_val in that unsorted part
    int min_val = *min_element(arr.begin() + s, arr.begin() + e + 1);
    int max_val = *max_element(arr.begin() + s, arr.begin() + e + 1);

    // In the sorted part if any number is greater than the min value
    for(int i = 0; i < s; i++) {
        if(arr[i] > min_val) {
            s = i;
            break;
        }
    }
    // In the sorted part from e to n , if anything is greater than the max value
    for(int i = n - 1; i > e; i--) {
        if(arr[i] < max_val) {
            e = i;
            break;
        }
    }

    return {s, e};
}
