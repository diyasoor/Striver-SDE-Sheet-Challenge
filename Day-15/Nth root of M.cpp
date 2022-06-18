double multiply(double m, int n) {
    double ans=1.00;
    for(int i=1;i<=n;i++) {
        ans *= m;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double lo = 1,hi = m+1;
    while((hi - lo) > 1e-8) {
        double mid = (hi + lo) / 2.00;
        if(multiply(mid,n) < (double)m) {
            lo = mid;
        }
        else hi = mid;
    }
    return lo;
}