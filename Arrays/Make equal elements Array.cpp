int Solution::solve(vector<int> &arr, int B) {
    long long int val1 = arr[0] - B;
    long long int val2 = arr[0] + B;
    long long int val3 = arr[0];
    int len = arr.size();
    int flag =1;
    for(int i=1; i<len; i++) {
        if(arr[i] != (val1 -B) && arr[i] != (val1+B) && arr[i] != val1) {
            flag =0;
            break; 
        }
    }
    if(flag) return 1;
    flag=1;
    for(int i=1; i<len; i++) {
        if(arr[i] != (val2 -B) && arr[i] != (val2+B) && arr[i] != val2) {
            flag =0;
            break; 
        }
    }
    if(flag) return 1;
    flag=1;
    for(int i=1; i<len; i++) {
        if(arr[i] != (val3 -B) && arr[i] != (val3+B) && arr[i] != val3) {
            flag =0;
            break; 
        }
    }
    return flag;
    
}
