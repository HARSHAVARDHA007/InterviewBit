void Solution::setZeroes(vector<vector<int> > &arr) {
    unordered_set<int>rows,cols;
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            if(arr[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for(auto ele : rows) {
        int row= ele;
        for(int j=0; j<arr[0].size(); j++) {
            arr[row][j] =0;
        }
    }
    for(auto ele : cols) {
        int col= ele;
        for(int j=0; j<arr.size(); j++) {
            arr[j][col] =0;
        }
    }
    return;
}
// Best approach is to use the first row and first column of the matrix instead of extra space used
// have 2 variables -> zero in 1st row , zero in 1st column
// iterate over remaining matrix and if you find the zero in i,j position
//make arr[0][j]=0 and arr[i][0]=0
// again iterate over the same area 
// if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
// fill first row and col with zeros if the 2 variables are true