/*
    Author  :   jignesh1604
    College :   SVNIT
*/

#include<bits/stdc++.h>
using namespace std;
long long int n;
vector<long long int> a, val, nextmax, nextmin;
vector<long long int> dp;

long long int fun(long long int ind) {
    if(dp[ind] != -1) return dp[ind];
    if(ind == n-1) {
        return val[n-1];
    }
    long long int ans = LLONG_MAX;
    if(nextmax[ind] != -1) {
        ans = min(ans, val[ind] + fun(nextmax[ind]));
    }
    if(nextmin[ind] != -1) {
        ans = min(ans, val[ind] + fun(nextmin[ind]));
    }
    return dp[ind] = ans;
}

void solve() {
    long long int i;
    cin >> n;
    a = vector<long long int> (n+1);
    val = vector<long long int> (n+1);
    dp = vector<long long int> (n+1 , -1);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(i = 0; i < n; i++) {
        cin >> val[i];
    }
    nextmax = vector<long long int> (n+1);
    nextmin = vector<long long int> (n+1);
    stack<long long int> st1 , st2;
    for(i = n-1; i >= 0; i--) {
        while(!st1.empty() && a[st1.top()] < a[i]) {
            st1.pop();
        }
        if(st1.empty()) {
            nextmax[i] = -1;
        }
        else {
            nextmax[i] = st1.top();
        }
        st1.push(i);
    }
    for(i = n-1; i >= 0; i--) {
        while(!st2.empty() && a[st2.top()] >= a[i]) {
            st2.pop();
        }
        if(st2.empty()) {
            nextmin[i] = -1;
        }
        else {
            nextmin[i] = st2.top();
        }
        st2.push(i);
    }
    cout << fun(0) << "\n";
}

int main() {
    long long int tc = 1;
    cin >> tc;
    while(tc-- > 0) {
        solve();
    }
}