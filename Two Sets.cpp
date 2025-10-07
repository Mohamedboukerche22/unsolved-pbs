//https://cses.fi/problemset/task/1092/
// 80/100 testcases
#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int N = 10e6 +1;

int main() {
    fastAOI;
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin  >>n;
        vector<ll>a,b;
        ll sum = (n)*(n+1) / 2;
        if(sum%2 == 1){cout<<"NO\n";return 0;}
        int ans = sum/2;
        for(ll i = n;i >=1;i--){
            if(i<= ans){
                a.pb(i); ans -=i;
            }else{
                b.pb(i);
            }
        }
        cout<<"YES\n"<<a.size()<<"\n";for(int i:a){cout<<i<<" ";};cout<<"\n";
        cout<<b.size()<<"\n";
        for(int i:b)cout<<i<<" ";


    }
    return 0;
}
