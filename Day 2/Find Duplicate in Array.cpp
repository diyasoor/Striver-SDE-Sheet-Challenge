#include<unordered_map>
int findDuplicate(vector<int> &arr, int n){
	unordered_map<int,int> map;
    int ans;
    for(int x:arr) {
        if(map.find(x)==map.end())
            map[x]++;
        else {
            ans = x;
            break;
        }
    }
    return ans;
}
