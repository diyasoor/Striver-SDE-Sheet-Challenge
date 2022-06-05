#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int maxProfit=0, minimum=INT_MAX;
    for(int i=0;i<prices.size();i++) {
        minimum = min(minimum, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minimum);
    }
    return maxProfit;
}