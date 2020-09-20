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


int main()
{
    fastio;
    ll i,j,n;
    t()
    {
        cin>>n;
        vector<ll>a(n),val(n);
        vector<ll> nge(n),nse(n); //stores indices 
        for(auto &it:a) cin>>it;
        for(auto &it:val) cin>>it;
        stack<int>s;
        for(i=n-1;i>=0;i--){
            while(!s.empty() && a[s.top()]<a[i]) s.pop();
            if(s.empty()) nge[i] = -1;
            else nge[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        // debugarray(nge,n);
        for(i=n-1;i>=0;i--){
            while(!s.empty() && a[s.top()]>=a[i]) s.pop();
            if(s.empty()) nse[i]=-1;
            else nse[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        // debugarray(nse,n);

        vector<ll>dp(n,LLONG_MAX);
        dp[0]=0;
        for(i=0;i<n;i++){
            dp[i] += val[i];
            if(nge[i]!=-1) dp[nge[i]] = min(dp[nge[i]],dp[i]);
            if(nse[i]!=-1) dp[nse[i]] = min(dp[nse[i]],dp[i]); 
        }
        // debugarray(dp,n);
        cout<<dp[n-1]<<"\n";
        

    }

}