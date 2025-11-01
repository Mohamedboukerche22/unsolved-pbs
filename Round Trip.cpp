#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

int main() {
    fastAOI;
    int t = 1;
    while (t--) {
        int n,m;
        cin >>n >>m;
        
        vector<vector<int>>adj(n+1);

        for(int i = 0 ; i< m ;i++){
            int u,v;
            cin >>u >>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        vector<int>visited(n+1,0),parent(n+1,-1);
        vector<int>circle;
        bool found = 0;

        for(int i = 1 ; i <= n && !found ;i++){
        if(visited[i])continue;
        
        queue<int>q;
        q.push(i);
        visited[i] = 1;


        while(!q.empty() && !found){
            int u = q.front();
            q.pop();


            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v] = 1;
                    parent[v] = u;
                    q.push(v);
                }else if(v != parent[u]){
                    circle.clear();
                   int x = u;
                   circle.pb(v);
                   while(x != v ){
                    circle.pb(x);
                    x = parent[x];
                   }

                   circle.pb(v);
                   reverse(all(circle));
                   found = true;
                   break;
                }
              }

           }
        }
        if(found){
            cout<<sz(circle)<<"\n";
            for(int c : circle){
                cout<<c<<" ";
            }
        }else{
            cout<<"IMPOSSIBLE"; 
        }
        
    }
    return 0;
}
