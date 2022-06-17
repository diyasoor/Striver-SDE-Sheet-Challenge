#define pb push_back
string kthPermutation(int n, int k) {
    // Write your code here.
    int fact=1;
    vector<int> nums;
    for(int i=1;i<n;i++) {
        fact = fact * i;
        nums.pb(i);
    }
    nums.pb(n);
    string ans = "";
    k = k - 1; //0-based indexing
    while(1) {
        ans = ans + to_string(nums[k/fact]);
        nums.erase(nums.begin() + (k/fact));
        if(nums.size()==0) break;
        k %= fact;
        fact /= nums.size(); 
    }
    return ans;
}
