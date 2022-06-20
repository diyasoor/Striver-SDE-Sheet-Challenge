bool isPossible(int n,int m, vector<int> &time, long long mid) {
    int day = 1;
    long long totalTime = 0;
    for(int i=0;i<m;i++) {
        if(time[i] > mid) return false;
        if(totalTime + time[i] > mid) {
            day += 1;
            totalTime = time[i];
            if(time[i] > mid) return false;
        }
        else {
            totalTime += time[i];
        }
    }
    if(day > n) return false;
    return true; 
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long lo = 0;
    long long hi = 0;
    for(int i=0;i<time.size();i++) {
        hi += time[i];
    }
    long long res = -1;
    while(lo <= hi) {
        long long mid = (lo + hi) / 2;
        if(isPossible(n,m,time,mid)) {
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return res;
}