int removeDuplicates(vector<int> &arr, int n) {
    if(n==0) return 0;
	int i=0,j=1;
    while(j<n) {
        if(arr[i]!=arr[j]) {
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    return i+1;
}