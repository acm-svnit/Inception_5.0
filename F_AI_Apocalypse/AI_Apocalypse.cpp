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
    string x;
    if(n==1){
        cout<<"A "<<1<<endl;
        cin >> x;
        return;
    }
    if(n==2){        
        cout<<"A "<<1<<endl;
        cin >> x;
        cout<<"A "<<1<<endl;
        cin >> x;
        return;
    }
    ll cur = 2;
    while(cur<=n-1){
        cout<<"A "<<cur<<endl;
        cin >> x;
        if(x=="Yes") return;
        cur++;
    }
    cur = n-1;
    while(cur>=2){
        cout<<"A "<<cur<<endl;
        cin >> x;
        if(x=="Yes") return;
        cur--;
    }
	return;
}
int main(){
	fastio;
	solve();	
	
}


