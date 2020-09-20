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
    ll i,j,n;
    string res;
    cin>>n;

    if(n==2)
    {
        cout<<"A "<<n<<"\n";
        fflush(stdout);
        cin>>res;
        if(res=="Yes") return 0;

        cout<<"A "<<n<<"\n";
        fflush(stdout);
        cin>>res;
        if(res=="Yes") return 0;

    }
    
    //assuming start from even index
    for(i=2;i<n;i++)
    {
        cout<<"A "<<i<<"\n";
        fflush(stdout);
        cin>>res;
        if(res=="Yes") return 0;
    }
    //assuming start from odd index
    j = (n-2)%2 ? 2 : 1 ;  //current possing is even or odd when start from odd index
    for(i=j;i<=n;i++)
    {
        cout<<"A "<<i<<"\n";
        fflush(stdout);
        cin>>res;
        if(res=="Yes") return 0;
    }


}