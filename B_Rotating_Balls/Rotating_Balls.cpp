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
ll maxDepth = 0;
vector<ll> level;
vector<ll> marthaThere;
vector<ll> parents;
ll martha = 0;
void dfs(ll node,ll parent, vector<vector<ll>> &edges,ll depth, ll flag){
    level[node] = depth;
    marthaThere[node] = flag;
    parents[node] = parent;
    if(node==martha) {
        flag = 1;
        marthaThere[node] = 1;
    }
    for(auto i: edges[node]){
        if(i==parent) continue;
        dfs(i,node,edges,depth+1,flag);
        if(marthaThere[i]) marthaThere[node] = 1;
    }
}

ll dfs1(ll node,ll parent,vector<vector<ll>> &edges){
    
    if(edges[node].size()==1) return 0;
    ll ans = 0;
    for(auto i: edges[node]){
        if(i==parent) continue;
        ans = max(ans,dfs1(i,node,edges));
    }
    return ans+1;
}
void solve(){
	ll n;
    cin >> n;
    if(n%2){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
    return;
}
int main(){
	
	whilet(){
		solve();			
	}	
	
}


