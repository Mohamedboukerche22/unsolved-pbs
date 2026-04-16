#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 +7;
struct BigInt {
    static const int base = 1000000000;
    vector<int> a;

    BigInt(long long v = 0) { *this = v; }

    BigInt& operator=(long long v) {
        a.clear();
        if (v == 0) return *this;
        while (v) {
            a.push_back(v % base);
            v /= base;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const BigInt& v) {
        if (v.a.empty()) return os << 0;
        os << v.a.back();
        for (int i = (int)v.a.size() - 2; i >= 0; i--)
            os << setw(9) << setfill('0') << v.a[i];
        return os;
    }

    BigInt operator*(int v) const {
        BigInt res;
        long long carry = 0;

        for (size_t i = 0; i < a.size() || carry; i++) {
            long long cur = carry;
            if (i < a.size()) cur += 1LL * a[i] * v;

            res.a.push_back(cur % base);
            carry = cur / base;
        }

        while (!res.a.empty() && res.a.back() == 0)
            res.a.pop_back();

        return res;
    }
    BigInt operator+(const BigInt& other) const {
    BigInt res;
    res.a.clear();
    long long carry = 0;
    for (size_t i = 0; i < max(a.size(), other.a.size()) || carry; ++i) {
        long long cur = carry + (i < a.size() ? a[i] : 0) + (i < other.a.size() ? other.a[i] : 0);
        res.a.push_back(cur % base);
        carry = cur / base;
    }
    return res;
}
BigInt operator%(int m) const {
    long long res = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        res = (res * base + a[i]) % m;
    }
    return res;
}
};


int main() {
	int n;cin>>n;
	
	BigInt a = 0,b = 1;
	for(int i=2;i<=n;i++){
	    BigInt x = a+b;
	    a = b%MOD; 
	    b = x%MOD; 
	}
	cout <<b;

}
