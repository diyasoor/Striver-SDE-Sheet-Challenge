vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while(i>=0 and j>=0) {
        if(arr1[i] <= arr2[j]) arr1[k--] = arr2[j--];
        else arr1[k--] = arr1[i--];
    }
    while(i>=0) arr1[k--] = arr1[i--];
    while(j>=0) arr1[k--] = arr2[j--];
    return arr1;
}