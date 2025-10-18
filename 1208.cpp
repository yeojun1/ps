#include <bits/stdc++.h>
using namespace std;
#define MAX 41
using ll = long long;

int N,S;
int A[MAX];
vector<ll> sums[2];
int ans;

void f(int i, ll sum, int ari)
{
    if ((ari==0 && i>=N/2) || (ari==1 && i>=N))
    {
        sums[ari].push_back(sum);
        return;
    }
    f(i+1,sum+A[i],ari);
    f(i+1,sum,ari);
}

int main()
{
    scanf("%d %d",&N,&S);
    for (int i=0;i<N;i++) scanf("%d",&A[i]);

    f(0,0LL,0);
    f(N/2,0LL,1);
    sort(sums[0].begin(),sums[0].end());
    sort(sums[1].begin(),sums[1].end());

    int e=sums[1].size()-1;
    for (size_t s=0;s<sums[0].size();s++)
    {
        while (e>=0 && sums[0][s]+sums[1][e]!=S) e--;
        while (e>=0 && sums[0][s]+sums[1][e]==S)
        {
            ans++;
            e--;
        }
    }

    printf("%d\n",ans);

    return 0;
}