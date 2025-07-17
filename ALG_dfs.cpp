#include <cstdio>
#include <vector>
#include <unordered_set>
#define MAXN 100001

int N,M,R,u,v; // N: 정점의 수, M: 제공되는 간선 정보의 수, R: 탐색 시작할 정점, u,v: 간선 정보  제공받을 때 쓸 임시 변수
vector<int> graph[MAXN];
vector<int> res;
unordered_set<int> visited;

void dfs(int n, unordered_set<int> &v)
{
    v.insert(n);
    res.push_back(n);

    for (int next : graph[n])
    {
        if (v.count(next) == 0)
        {
            dfs(next, v);
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);
    for (int i=0;i<M;i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(R, visited);
    for (int i : res)
    {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
