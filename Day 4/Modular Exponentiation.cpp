#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
    long newX = x;
    long ans = 1;
    while(n > 0) {
        if(n%2) {
            ans = (ans * newX%m) % m;
            n -= 1;
        }
        else {
            newX = (newX%m * newX%m) % m;
            n /= 2;
        }
    }
    return (int)(ans % m);
}