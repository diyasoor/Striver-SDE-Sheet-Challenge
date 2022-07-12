/* recursion:
if(f==0 || f==1) return f;
if(e==1) return f;

int mn = INT_MAX;
for(int i=1;i<=f;i++) {
    int temp = 1 + max(cutLogs(e-1,i-1), cutLogs(e, f-i));
    mn = min(mn, temp);
}
return mn;
*/

// egg drop
// k = number of eggs
// n = number of floors
int binomialCoeff(int x, int e, int f)
{
    int sum = 0, term = 1;
    for (int i = 1; i <= e; ++i) {
        term *= x - i + 1;
        term /= i;
        sum += term;
        if(sum>f) return sum;
    }
    return sum;
}
int cutLogs(int e, int f)
{
    // Write your code here.
    int low = 1, high = f;
    while (low < high) {
        int mid = (low + high) / 2;
        if (binomialCoeff(mid, e, f) < f)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
