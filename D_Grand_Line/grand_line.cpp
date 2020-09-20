#include<bits/stdc++.h>
using namespace std;
vector<long long int> dp(1000005 , 1);

void initialize() {
    for(long long int i = 2 ; i < 1000002 ; i++) {
        for(long long int j = 2*i ; j < 1000003 ; j+=i) {
            dp[j] += dp[i];
        }
    }
    dp[1] = 0;
}

void solve() {
    long long int n , i;
    cin >> n;
    cout << dp[n] << "\n";

}

int main() {
    initialize();
    long long int tc = 1;
    cin >> tc;
    while(tc-- > 0) {
        solve();
    }
}