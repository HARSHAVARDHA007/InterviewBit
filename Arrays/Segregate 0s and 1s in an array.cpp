vector<int> Solution::solve(vector<int> &arr)
{
    int n = arr.size(), i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] == 1)
        {
            // we have a 1 now find first 0 from right side
            while (j > i && arr[j] == 1)
            {
                j--;
            }
            if (j <= i)
            {
                // haven't found a one
                break;
            }
            else
            {
                // if found then swap them
                swap(arr[i], arr[j]);
            }
        }
        i++;
    }
    return arr;
}
