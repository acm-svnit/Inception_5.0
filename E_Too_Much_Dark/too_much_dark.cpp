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
int n,m,root,stop,ans;
const int N = 1e5+2;
vector<int> v[N],level(N),child(N);

int dfs(int x,int parent) {
  
  bool onPath = 0;
  if(x == stop)
    onPath = 1;
  for(int i: v[x]) {
    if(i == parent) continue;
    level[i] = level[x] + 1;
    int res = dfs(i,x);
    if(!res) {  
      child[x] = max(child[x] , 1 + child[i]);
    }else
      onPath = 1;
  }
  if(onPath && level[x] > level[stop] - level[x]) 
    ans = max(ans, level[x] + child[x]);
  return onPath;
} 

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  w(tt) {
    cin >> n;
    m = n - 1;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    } 
    cin >> root >> stop;
    dfs(root,-1);
    cout << ans << "\n";
    //******UNDO*********
    for(int i = 1; i <= n; ++i) {
      level[i] = 0;
      v[i].clear();
      child[i] = 0;
    }
    ans = 0;
  }
  
  return 0;
}

