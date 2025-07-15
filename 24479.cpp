#include <cstdio>
#include <map>
#include <set>
#include <vector>

using namespace std;

int N,M,R,A,B;
map<int, set<int>> graph;
set<int> visited;
vector<int> rst;

void dfs(int node, set<int>& v)
{
    v.insert(node);
    rst.push_back(node);

    for (int n : graph[node])
    {
        if (v.count(n) == 0)
        {
            dfs(n, v);
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

    dfs(R, visited);
    for (int i=0;i<N;i++)
    {
        if (visited.count(i+1) == 0)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", rst[i]);
    }

    return 0;
}
