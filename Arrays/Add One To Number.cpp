#include<bits/stdc++.h>
using namespace std;
vector<int> Solution::plusOne(vector<int> &A) {
    int total_len = A.size();
    int zeros = 0;
    int all_nines = 1, non_zero_seen = 0;
    // Find no of trailing zeros and if the input has all the 9's 
    for(int i=0; i<total_len; i++) {
        if(A[i] != 0) {
            non_zero_seen = 1;
        }
        if(A[i] !=9 && non_zero_seen) {
            all_nines = 0;
        }
        if(A[i] == 0 && !non_zero_seen ) {
            zeros++;
        }
    }
    // If all 9 nines then ans will have an extra 1 at the beginning
    int ans_len = all_nines ? total_len - zeros + 1 : total_len - zeros;
    vector<int>ans(ans_len);
    int carry = 1;
    for(int i=total_len-1; i>=zeros; i--){
        ans[i-zeros] = (A[i] + carry)%10;
        // Have to carry 1 forward if the input is 10
        carry = A[i] + carry == 10 ? 1 : 0;
    }
    if(carry == 1) {
        ans[0] = carry;
    }
    return ans; 
}
