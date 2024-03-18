void Solution::rotate(vector<vector<int>> &A)
{
  int n = A.size();
  int row = 0;
  // Transpose
  while (row < n)
  {
    for (int col = row; col < n; col++)
    {
      swap(A[row][col], A[col][row]);
    }
    row++;
  }
  // Reverse
  int i = 0, j = n - 1;
  while (i < j)
  {
    for (int row = 0; row < n; row++)
    {
      swap(A[row][i], A[row][j]);
    }
    i++;
    j--;
  }
  return;
}
