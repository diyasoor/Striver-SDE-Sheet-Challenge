void sort012(int *arr, int n)
{
    int lo = 0, mid = 0, hi = n - 1;
	while(mid <= hi) {
		if(arr[mid]==0) {
            swap(arr[lo], arr[mid]);
            lo++;
            mid++;
        }
        else if(arr[mid]==1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[hi]);
            hi--;
        }
	}
	return;
}