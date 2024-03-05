int Solution::solve(vector<string> &A) {
    int rows = A.size(),cols = A[0].size();
    
    unordered_map<char,int> maxRow[cols],minRow[cols],maxCol,minCol;
    // To maximise base distance we use maxRow and minRow for 'r', 'g', 'b' in each column.
    // To maximise height we store maxCol and minCol for each color
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            maxRow[j][A[i][j]] = max(maxRow[j][A[i][j]],i);
            maxCol[A[i][j]] = max(maxCol[A[i][j]],j);
            minRow[j][A[i][j]] = minRow[j].find(A[i][j]) == minRow[j].end() ?  i : min(minRow[j][A[i][j]],i);
            minCol[A[i][j]] = minCol.find(A[i][j]) == minCol.end() ? j : min(minCol[A[i][j]],j);
        }
    }
    int ans = 0;
    for(int col = 0;col<cols;col++)
    {
        int maxBase,maxHeight;
        //R,G as base vertices and B as third vertex
        if(maxRow[col].count('r') and maxRow[col].count('g') and maxCol.count('b'))
        {
            maxBase = max(abs(maxRow[col]['r']-minRow[col]['g']),abs(minRow[col]['r']-maxRow[col]['g']))+1;
            maxHeight = max(abs(col-maxCol['b']),abs(col-minCol['b']))+1;
            ans = max(ans,maxBase*maxHeight);
        }
        //G,B as base vertices and R as third vertex
        if(maxRow[col].count('g') and maxRow[col].count('b') and maxCol.count('r'))
        {
            maxBase = max(abs(maxRow[col]['g']-minRow[col]['b']),abs(minRow[col]['g']-maxRow[col]['b']))+1;
            maxHeight = max(abs(col-maxCol['r']),abs(col-minCol['r']))+1;
            ans = max(ans,maxBase*maxHeight);
        }
        //B,R as base vertices and G as third vertex
        if(maxRow[col].count('b') and maxRow[col].count('r') and maxCol.count('g'))
        {
            maxBase = max(abs(maxRow[col]['b']-minRow[col]['r']),abs(minRow[col]['b']-maxRow[col]['r']))+1;
            maxHeight = max(abs(col-maxCol['g']),abs(col-minCol['g']))+1;
            ans = max(ans,maxBase*maxHeight);
        }
    }
    return ceil(ans/2.0);
    
}
