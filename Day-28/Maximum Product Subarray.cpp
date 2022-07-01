int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int curMax = arr[0], curMin = arr[0], ans = arr[0];
        for(int i=1;i<n;i++) {
            int n = arr[i];
            int temp = n * curMax;
            curMax = max(max(n * curMax, n * curMin), n);  // ex: [-1,8]  -> max(-1 * 1, -1 * 1, n = 8)
            curMin = min(min(temp, n * curMin), n);     // ex: [-1,-8] -> min(-1 * 1, -1 * 1, n = -8)
            
            ans = max(ans, curMax);
        }
        return ans;
}
