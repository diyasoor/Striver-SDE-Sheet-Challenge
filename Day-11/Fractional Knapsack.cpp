#include<algorithm>
bool static comp(pair<int, int> i1, pair<int, int> i2) {
    double v1 = (double)i1.second / (double)i1.first;
    double v2 = (double)i2.second / (double)i2.first;
    return v1 > v2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comp);  
    int currWeight = 0;
    double maxValue = 0.0;

    for(int i=0;i<n;i++) {
        if(currWeight + items[i].first <= w) {
            currWeight += items[i].first;
            maxValue += items[i].second;
        }
        else {
            int remain = w - currWeight;
            maxValue += ((double)items[i].second / (double)items[i].first) * (double)remain;
            break; 
        }
    }
    return maxValue;
}