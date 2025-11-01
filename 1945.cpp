#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,ll> p_pll_ll;

ll N;
ll xbl,ybl,xtr,ytr;
vector<p_pll_ll> slope;

ll cnt,mx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (size_t i=0;i<N;i++)
    {
        cin >> xbl >> ybl >> xtr >> ytr;
        slope.push_back({{xtr,ybl},1});
        slope.push_back({{xbl,ytr},-1});
    }
    sort(slope.begin(),slope.end(),
    [](p_pll_ll a, p_pll_ll b)
    { return b.first.first * a.first.second < a.first.first * b.first.second; });

    for (size_t i=0;i<slope.size();i++)
    {
        cnt += slope[i].second;
        if (mx<cnt) mx=cnt;
    }

    cout << mx << "\n";

    return 0;
}