#include<climits>
int atoi(string str) {
    // Write your code here.
    int n = str.length();
    int num = 0;
    int i=0;
    int sign = 1;
    if(str[i]=='-') {
        sign = -1;
        i++;
    }
    for(int i=0;i<n;i++) {
        if(str[i]-'0' >= 0 && str[i]-'0' <= 9) {
            num = (num * 10) + str[i] - '0';
        }
    }
    return num*sign;
}