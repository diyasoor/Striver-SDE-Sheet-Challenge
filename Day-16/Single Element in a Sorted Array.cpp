int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int lo = 0;
    int hi = n-1;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(mid && arr[mid]==arr[mid-1]) {
            if((mid - lo)%2==0) {
                hi = mid - 2;
            }
            else lo = mid + 1;
        }
        else if(mid+1 <n && arr[mid]==arr[mid+1]) {
            if((hi - mid)%2==0) {
                lo = mid + 2;
            }
            else hi = mid - 1;
        }
        else return arr[mid]; 
    }
    return -1;
}
