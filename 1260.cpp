#include <cstdio>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

int N,M,V,A,B;
map<int, set<int>> graph;
unordered_set<int> visited;

void dfs(int node, unordered_set<int>& v)
{
    v.insert(node);
    printf("%d ", node);

    for (int n : graph[node])
    {
        if (v.count(n) == 0)
        {
            dfs(n, v);
        }
    }
}

void bfs()
{
    set<int> visited;
    queue<int> q;

    visited.insert(V);
    q.push(V);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        printf("%d ", node);
        for (int n : graph[node])
        {
            if (visited.count(n) == 0)
            {
                visited.insert(n);
                q.push(n);
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &V);
    for (int i=0;i<M;i++)
    {
        scanf("%d %d", &A, &B);
        graph[A].insert(B);
        graph[B].insert(A);
    }

    dfs(V, visited);
    printf("\n");

    bfs();
    printf("\n");

    return 0;
}
