#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int M;
int l,r;
vector<pii> LINES;
vector<pii> ans;
int idx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M;
    while (1)
    {
        cin >> l >> r;
        if (l==0 && r==0) break;
        LINES.push_back({l,r});
    }
    sort(LINES.begin(),LINES.end());

    // 0을 포함하면서 끝점이 가장 큰 선분
    idx = upper_bound(LINES.begin(),LINES.end(),make_pair(0,50001))-LINES.begin();

    return 0;
}