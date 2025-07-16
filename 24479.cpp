#include <cstdio>
#include <map>
#include <set>
#include <vector>
#define MAXN 100001

using namespace std;

int N,M,R,A,B;
map<int, set<int>> graph;
set<int> visited;
int rst[MAXN];

void dfs(int node, set<int>& v, int idx)
{
    v.insert(node);
    rst[idx] = node;

    for (int n : graph[node])
    {
        if (v.count(n) == 0)
        {
            dfs(n, v, idx+1);
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);
    for (int i=0;i<M;i++)
    {
        scanf("%d %d", &A, &B);
        graph[A].insert(B);
        graph[B].insert(A);
    }

    dfs(R, visited, 0);

    for

    return 0;
}
