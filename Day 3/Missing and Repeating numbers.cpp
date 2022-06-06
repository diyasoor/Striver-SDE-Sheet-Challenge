#include<set>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int rep,sum=0;
	set<int> set;
    for(auto x:arr) {
        if(set.find(x)==set.end()) {
            sum += x;
        }
        else {
            rep = x;
        }
        set.insert(x);
    }
    int total = (n*(n+1))/2;
    int mis = total - sum;
    return make_pair(mis,rep);
}
