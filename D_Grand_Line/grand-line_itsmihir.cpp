#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 

#define int long long
#define mod 1000000007
#define pb push_back
#define S second
#define F first
#define INF 1e18
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define deb(x) cerr << "\n" \
                    << #x << "=" << x << "\n";
#define deb2(x, y) cerr << "\n" \
                        << #x << "=" << x << "\n" \
                        << #y << "=" << y << "\n";
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)

const int N = 2e5;
int dp[N];
void init(){
    for(int i = 2;i<N;i++) dp[i] = 1;
    for(int i = 2; i<N;i++)
        for(int j = 2*i;j<N;j+=i)
            dp[j] += dp[i];
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  w(tt) {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
  }
  return 0;
}
