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

using namespace std;

void solve(){
	ll n;
    cin >> n;

    vector<pair<ll,ll>> arr(n,{0,0});
    for(auto& i: arr) cin >> i.F;
    for(auto& i: arr) cin >> i.S;
    vector<ll> minX(n,-1),maxX(n,-1);
    stack<ll> s,s1;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            s.push(i);
            s1.push(i);
            continue;
        }
        while(!s.empty() && arr[s.top()].F<arr[i].F) s.pop();
        if(!s.empty()){
            maxX[i] = s.top();
        }
        s.push(i);
        while(!s1.empty() && arr[s1.top()].F>=arr[i].F) s1.pop();
        if(!s1.empty()){
            minX[i] = s1.top();
        }
        s1.push(i);
    }
    vector<ll> dp(n,LLONG_MAX);
    dp[0] = arr[0].S;
    // for(auto i: minX) cout<<i<<" ";
    // cout<<endl;
    // for(auto i: maxX) cout<<i<<" ";
    // cout<<endl;
    f(i,0,n-1){
        if(minX[i]!=-1){
            dp[minX[i]] = min(dp[minX[i]],dp[i] + arr[minX[i]].S);
        }
        if(maxX[i]!=-1){
            dp[maxX[i]] = min(dp[maxX[i]],dp[i] + arr[maxX[i]].S);
        }
    }
    // for(auto i: dp) cout<<i<<" ";
    // cout<<endl;
    cout<<dp[n-1]<<endl;
    return;
}
int main(){
	
	whilet(){
		solve();			
	}	
	
}


