//https://cses.fi/problemset/task/1135/
//its work on bfs but on small input but in this case ig i should use LCA  dw i'll learnt and solve it buy it 
#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

vector<vector<ll>>adj;
ll bfs(ll n,ll a, ll b){
    ll start = a;
    vector<ll>dist(n+1,-1);
    dist[start] = 0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int v = q.front(); 
        q.pop();
        for(auto u : adj[v]){
            if(dist[u] == -1){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist[b];

}

int main() {
    fastAOI;
    int t = 1;
    // cin >> t;
    while (t--) {
       ll n,q;
       cin >> n >> q;
       adj.assign(n+1,{});
       for(ll i = 0 ; i< n-1;i++){
        ll u,v;cin >>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
       }
       while(q--){
        ll a,b;
        cin >>a>>b;
       // cout << max(bfs(n,a,b),bfs(n,b,a))<<"\n";
       cout << bfs(n,a,b)<<"\n";
       }
    
    }
    return 0;
}
