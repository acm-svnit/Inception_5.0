#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int>> adj;
vector<bool> visited;
vector<long long int> parent;

void dfs(long long int node) {
    visited[node] = true;
    for(long long int i = 0 ; i < adj[node].size() ; i++) {
        if(!visited[adj[node][i]]) {
            dfs(adj[node][i]);
            parent[adj[node][i]] = node;
        }
    }
}

long long int dfs2(long long int node , long long int x) {
    long long int ans = 0;
    for(long long int i = 0 ; i < adj[node].size() ; i++) {
        if(adj[node][i] == x) continue;
        ans = max(ans , dfs2(adj[node][i] , node));
    }
    return ans+1;
}

void solve() {
    long long int n , i , x , y;
    cin >> n;
    adj = vector<vector<long long int>> (n+1);
    visited = vector<bool> (n+1);
    parent = vector<long long int> (n+1 , -1);
    for(i = 1 ; i <= n-1 ; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long int p , q;
    cin >> x >> y;
    if(x == y) {
        cout << 0 << "\n";
        return;
    }
    p = x , q = y;
    vector<long long int> v1 , v2;
    map<long long int , long long int> mp;
    dfs(1);
    while(x != -1) {
        v1.push_back(x);
        x = parent[x];
    }
    while(y != -1) {
        mp[y] = 1;
        y = parent[y];
    }
    x = p , y = q;
    long long int lca;
    for(i = 0 ; i < v1.size() ; i++) {
        if(mp[v1[i]] == 1) {
            lca = v1[i];
            break;
        }
    }
    vector<long long int> v , temp;
    x = p , y = q;
    while(x != lca) {
        v.push_back(x);
        x = parent[x];
    }
    v.push_back(x);
    while(y != lca) {
        temp.push_back(y);
        y = parent[y];
    }
    reverse(temp.begin() , temp.end());
    for(i = 0 ; i < temp.size() ; i++) v.push_back(temp[i]);
    long long int mid = (v.size()-1)/2;
    long long int ans = dfs2(v[mid+1] , v[mid]);
    cout << ans+mid << "\n";
}

int main() {
    long long int tc;
    cin >> tc;
    while(tc-- > 0) {
        solve();
    }

}