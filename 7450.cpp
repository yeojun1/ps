#include <cstdio>
#define MAX 100001

int N,L;
int item[MAX];

int main()
{
    scanf("%d %d",&N,&L);
    for (int i=0;i<N;i++) scanf("%d",&item[i]);
    return 0;
}

// 오름차순 sorting
// 처음으로 L/2를 넘는 원소 idx 구함 (이분탐색)
// rst += L/2이하 갯수/2가 한 상자에 들어갈 수 있는 갯수
// 만약 L/2이하 갯수/2가 홀수면 하나는 따로 들어가야 함
// - if (L/2이하 갯수%2==1) rst++
// rst += L/2초과갯수