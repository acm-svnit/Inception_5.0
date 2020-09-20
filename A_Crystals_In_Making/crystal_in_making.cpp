#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t-- > 0) {
        long long int n, i , ans = 0;
        cin >> n;
        for(i = 0 ; i < 64 ; i++) {
            if((1ll << i) & n) ans++;
        }
        cout << ans << "\n";
    }
}