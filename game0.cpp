/*
lien = https://codeforces.com/problemset/problem/2078/D
Author = mohamed boukerche
Date = 8 jul 2025
Status = happy
the first clean code 
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
using INT=int;
const int MAXA = 15000001;
int gcd(int a,int b)
{
    return __gcd(a,b);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        INT L = 1,R = 1;
        while(n--)
        {
            char operationL ;
            cin >> operationL;
            int numberL;
            cin >> numberL;

            char operationR ;
            cin >> operationR;
            int numberR;
            cin >> numberR;

            INT LO = 0,RO = 0;
            if(operationL == 'x') 
            {
                LO = L * (numberL - 1);
            } 
            else 
            {
              LO = numberL;
            }

            if(operationR == 'x') 
            {
               RO = R * (numberR - 1);
            } 
            else 
            {
              RO = numberR;
            }

        int total_new_people = LO + RO ;
            int L_NEW = 0;
            int R_NEW = 0;

            INT BESTL = 0,BESTR = 0;
            INT MAXT = 0;
            for(int i=0;i<=total_new_people;++i)
            {
                L_NEW = L + i;
                R_NEW = R + (total_new_people - i);
               if(L_NEW + R_NEW > MAXT)
                {
                    MAXT = L_NEW + R_NEW ;
                    BESTL = L_NEW;
                    BESTR = R_NEW;

                }

            }
            L = BESTL;
            R = BESTR;

        }
        cout <<(L + R)<<"\n";
    }

}
