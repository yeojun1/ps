#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int M,L,R;
vector<pii> LINE;
vector<pii> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M;
    while (1)
    {
        cin >> L >> R;
        if (L==0 && R==0) break;
        LINE.push_back({L,R});
    }
    sort(LINE.begin(),LINE.end());

    ans.push_back({0,0});
    while (ans.back().second < M)
    {
        auto next_idx = upper_bound(LINE.begin(), LINE.end(), pii(ans.back().second, INT_MIN),
        [](const pii &a, const pii &b){ return (a.first == b.first) ? a.second < b.second : a.first < b.first; })
        - LINE.begin() - 1;
        ans.push_back(LINE[next_idx]);
    }

    cout << ans.size()-1 << "\n";

    return 0;
}