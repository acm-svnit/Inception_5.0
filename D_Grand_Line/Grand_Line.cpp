/*
	author: KRHero
	IDE: VSCode	
*/

#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=b;i>a;i--)
#define fde(i,a,b) for(int i=b;i>=a;i--)
#define fastio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define MID(s,e) (s+(e-s)/2)
#define whilet() int t; cin >> t;while(t--)
#define F first
#define S second
#define mp make_pair
#define epsilon 1e-15
#define pb push_back
#define PI 3.1415926535897932384626433832
#define MAX 1000005
using namespace std;
vector<ll> dp(MAX,0);
void setDP(){
    for(int i = 2;i<MAX;i++) dp[i] = 1;

    for(int i = 2; i<MAX;i++)
        for(int j = 2*i;j<MAX;j+=i)
            dp[j] += dp[i];
}
void solve(){
	ll n;
    cin >> n;
    cout<<dp[n]<<endl;
    return;
}
int main(){
	fastio;
    setDP();
    whilet()
	    solve();
	
}


