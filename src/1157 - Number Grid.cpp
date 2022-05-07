/*
Problem Name: Number Grid
Problem Link: https://cses.fi/problemset/task/1157
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", (x-1) ^ (y-1));
    return 0;
}