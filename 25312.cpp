#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 100001
using namespace std;

int N,M;
int w,v;
int sum,sugar;
pair<int,int> juices[MAX];

bool comp(pair<int,int> p1,pair<int,int> p2) {return p1.second<p2.second;}

int main()
{
    scanf("%d %d",&N,&M);
    for (int i=0;i<N;i++) scanf("%d %d",&w,&v);
    sort(juices,juices+N,comp); // 설탕량 기준 내림차순

    int i=0;
    while (sum>0)
    {
        sugar+=juices[i].second;
        sum-=juices[i].first;
        i++;
    }
    if (sum<0) sugar+=juices[i].second/juices[i].first*sum;
    string str_sugar=to_string(sugar);
    int de=10^(str_sugar.length()-1);
    int nu=sugar*de;
    int gcd=__gcd(de,nu);
    // printf("%d/%d\n",nu/gcd,de/gcd);
    printf("%d",sugar);

    return 0;
}