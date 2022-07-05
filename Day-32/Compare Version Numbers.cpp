int compareVersions(string a, string b) 
{
    // Write your code here
    int s1 = a.size(), s2 = b.size();
    int i=0, j=0;
    
    while(i<s1 || j<s2) {
        long long num1 = 0, num2 = 0;
        while(i<s1 && a[i]!='.') {
            num1 = num1 * 10 + 1ll * (a[i] - '0');
            i++;
        }
        while(j<s2 && b[j]!='.') {
            num2 = num2 * 10 + 1ll * (b[j] - '0');
            j++;
        }
        if(num1 > num2) return 1;
        if(num1 < num2) return -1;
        i++, j++;
    }
    return 0;
}