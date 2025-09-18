// btw i used boukerche-binary-serach lol 
#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int BBS(int t,vector<int>& a){
    vector<pair<int,int>>arr;
    int n = a.size();
    for(int i = 0 ; i<  n ;i++){
        arr.push_back({a[i],i});
    }
    sort(arr.begin(),arr.end());

    int l = 0,r = n-1;
    while(l <= r){
        int mid = (l+r) / 2;
        if(arr[mid].first == t){
           return arr[mid].second;
        }
        else if(mid > t){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;

}
int main(){
    int n,t;
    cin >>n >>t;
    vector<int>a(n);
    for(int i= 0 ; i<  n ;i++){
        cin >> a[i];
    }
    if(a.size()==1 && a[0] == t){
        cout << "IMPOSSIBLE"; 
        return 0;
    }
    for(int i = 0 ; i< n/2 +1 ; i++){
        int s2 = t - a[i]; 
        if(s2 == a[i]){
            continue;
        }
        int ss = BBS(s2,a);
        if(ss != -1){
            int a = i+1 ;
            int  b = ss+1;
            cout << min(a,b)<<" "<<max(a,b);
            
            return 0;
        } 
    }
    cout << "IMPOSSIBLE";
    
}
