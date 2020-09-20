#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define debug3(x, y,z) cout << #x << " = " << x << "   " << #y << " = " << y << " "<<#z<<" = "<<z<<"\n";
#define debugarray(arr,n) { cout << "[" ; for(ll i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"] , \n";}

const ll MAX = 1e6+1;
ll dp[MAX] = {};
void solve()
{
    for(ll i=2;i<MAX;i++)
        dp[i] = 1;
    for(ll i=2;i<MAX;i++)
        for(ll j=2*i;j<=MAX;j+=i)
            dp[j] += dp[i];
}


int main()
{
    fastio;
    ll i,j,n;
    solve();
    t()
    {
        cin>>n;
        cout<<dp[n]<<'\n';
    }

}