int countElements(vector<int> &arr, int midNum) {
    int lo = 0, hi = arr.size() - 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(arr[mid] <= midNum) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int lo = 1;
    int hi = 1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        // number of elements less than or equal to mid 
        int cnt = 0;
        for(int i=0;i<n;i++) {
            cnt += countElements(matrix[i], mid);
        }
        if(cnt <= (n * m) / 2) {
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return lo;
}