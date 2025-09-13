#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int N;
int s,e;
vector<pair<int,int>> meetings,room;

bool cmp(pair<int,int> i,pair<int,int> j) { return i.second<j.second; }

int main()
{
    scanf("%d",&N);
    for (int i=0;i<N;i++)
    {
        scanf("%d %d",&s,&e);
        meetings.push_back(make_pair(s,e));
    }
    // 빨리 끝나는 순
    sort(meetings.begin(),meetings.end(),cmp);

    return 0;
}