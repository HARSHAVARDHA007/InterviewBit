int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int len = A.size();
    int ans = 0;
    int start_x = A[0];
    int start_y = B[0];
    for(int i=1; i<len; i++) {
        ans = ans + max(abs(A[i]-start_x), abs(B[i]-start_y));
        start_x = A[i];
        start_y = B[i];
    }
    return ans;
}
