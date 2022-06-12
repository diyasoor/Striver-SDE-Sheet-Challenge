int longestSubSeg(vector<int> &arr , int n, int k){
    int left =0, right=0, maxLen=0, flippedCnt =0;
    while(right < n) {
        if(arr[right]==1) {
            right++;
        }
        else {
            if(flippedCnt < k) {
                flippedCnt++;
                right++;
            }
            else {
                while(flippedCnt >= k) {
                    if(arr[left]==0)  flippedCnt--;
                    left++;
                }
            }
        }
        maxLen = max(maxLen, right-left);
    }
    return maxLen;
}
