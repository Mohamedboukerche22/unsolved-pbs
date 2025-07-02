/*
Author = mohamed boukerche
Date = 2 jul 2025
Status = !happy
*/
#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
using std::ios;
using std::unordered_set;
using std::string;
using std::min;
using std::max;
using std::__gcd;
using std::lower_bound;
using ll = long long;
using str = string;
const int MAXA = 15000001;
int gcd(int a,int b)
{
    return __gcd(a,b);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int g = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }

    for (int i = 0; i < n; ++i)
        a[i] /= g;

    vector<int> freq(MAXA, 0);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        unordered_set<int> primes;

        for (int p = 2; p * p <= x; ++p) {
            if (x % p == 0) {
                primes.insert(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) primes.insert(x);

        for (int p : primes)
            freq[p]++;
    }

    int best = 0;
    for (int i = 2; i < MAXA; ++i)
        best = max(best, freq[i]);

    if (best == 0) cout << -1 << '\n';
    else cout << n - best << '\n';

    return 0;
}
