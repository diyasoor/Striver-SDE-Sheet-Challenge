int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int platCnt=1,i=1,j=0,maxPlat=1;
    while(i < n && j < n) {
        if(at[i] <= dt[j]) {
            platCnt++;
            i++;
        }
        else {
            platCnt--;
            j++;
        }
        maxPlat = max(maxPlat,platCnt);
    }
    return maxPlat;
}