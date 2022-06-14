int findMinimumCoins(int amount) 
{
    vector<int> coins{1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();
    int cnt = 0;
    for(int i=n-1;i>=0;i--) {
        while(coins[i] <= amount) {
            cnt++;
            amount -= coins[i];
        }
    }
    return cnt;
}
