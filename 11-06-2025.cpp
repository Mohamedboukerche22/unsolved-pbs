#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unsigned int cal(int k, set<int>&calc)
{
    vector<int>lol;
 auto m_i_n  = min_element(calc.begin(), calc.end(), [](int a, int b) {
        if (a == 0) return false;
        if (b == 0) return true;
        return a < b;
    });
    int m_i_né = *min_element(lol.begin(),lol.end());
    while(*m_i_n > k)
    { 
        for(int i=0;i<calc.size();i++)
        {
          if(m_i_né * lol.size() <= k)
          {
           
          }
        }


      
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >>n>>k;
        vector<int>team(n);
        set<int>calc;
        for(int &i:team)
        {
            cin >>i;
            calc.insert(i);
        }
        sort(team.begin(),team.end());
        reverse(team.begin(),team.end());
        cout<<cal(k,calc);

    }

    return 0;
}
