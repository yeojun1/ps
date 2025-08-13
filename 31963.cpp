// from math import log2,ceil,floor
// N = int(input())
// A = list(map(int, input().split()))
// res=[0]

// for i in range(1,N):
//     res.append(max(0,int(ceil(log2(A[i-1]/A[i])))+res[i-1]))

// print(sum(res))

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <numeric>
#define MAXN 250001
using namespace std;
typedef long long ll;

int N;
ll A[MAXN],rst[MAXN]={0LL};

int main()
{
    scanf("%d",&N);
    for (int i=0;i<N;i++) scanf("%lld",&A[i]);
    
    for (int i=1;i<N;i++) {
        rst[i]=max(0LL, (ll)ceil(log2((double)A[i-1]/A[i]))+rst[i-1]);
    }

    printf("%lld\n",accumulate(rst,rst+N,0LL));
    return 0;
}