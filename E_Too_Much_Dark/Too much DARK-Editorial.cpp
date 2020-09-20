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

vector<vector<ll>>g;
vector<ll>parent;//stores parent of each node
vector<ll>maxdepth; //stores max depth in subtree 
vector<ll>level;//level of each node
void dfs(ll s,ll par=-1)
{
    parent[s]=par;
    maxdepth[s] = 0;
    for(auto to:g[s]){
        if(to!=par){
            level[to] = level[s]+1;
            dfs(to,s);
            maxdepth[s] = max(maxdepth[s],maxdepth[to]);
        }
    }
    maxdepth[s]++;
}

int main()
{
    fastio;
    // freopen("a.in","r",stdin);
    t()
    {
        ll i,j,n,u,v,jonas,martha;
        cin>>n;
        g = vector<vector<ll>>(n+1);
        parent = vector<ll>(n+1);
        maxdepth = vector<ll>(n+1);
        level = vector<ll>(n+1);
        for(i=0;i<n-1;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cin>>jonas>>martha;
        dfs(jonas);
        ll ans = 0;
        ll s = martha;
        while(jonas!=s){
            if(level[s] > level[martha]-level[s] ){
                ans = max(ans,maxdepth[s]+level[s]-1);
            }
            s=parent[s];
        }
        cout<<ans<<'\n';

    }
    


}