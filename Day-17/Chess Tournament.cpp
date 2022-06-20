bool canPlace(int C,int n,vector<int>& pos,int separation) {
    int chess =1;
    int location = pos[0];
    for(int i=1;i<n;i++) {
        if(pos[i] - location >= separation) {
            chess++;
            location = pos[i];
        }
        if(chess==C) return true;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end());
    int lo=0;
    int hi=positions[n-1] - positions[0];
    int ans=-1;
    while(lo<=hi) {
        int mid = (lo + hi)/2;
        if(canPlace(c,n,positions,mid)) {
            ans = mid;
            lo = mid + 1; // as we are trying to maximize our ans
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}