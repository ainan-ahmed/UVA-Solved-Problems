#include <bits/stdc++.h>
using namespace std;
typedef                 long long ll;
typedef                 unsigned long long ull;
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<int,pii>
#define vi              vector<int>
#define PI              acos(-1)
#define all(v)          v.begin(),v.end()
#define sc(a)           scanf("%d",&a)
#define scll(a)         scanf("%I64d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define mmset(a,val)    memset(a,val,sizeof(a))
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)    scanf("%d%d%d%d",&a,&b,&c,&d)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%I64d\n",a)
#define pb(a)           push_back(a)
#define tcs(tc,t)       for(tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX               102
vi edges[MX];
bool visited[MX];
int dfs(int u)
{
    int cnt=1;
    visited[u]=1;
    int len=edges[u].size();
   // cout<<len<<" "<<u<<endl;
    for(int i=0;i<len;i++)
    {

        int v=edges[u][i];
        if(!visited[v]){
            visited[v]=1;
            int tmp=dfs(v);

            cnt+=tmp;


        }
    }
    return cnt;

}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,k,a;
    while(sc(n)&&n!=0)
    {
        for(int i=1; i<=n; i++)
        {
            sc(k);
            for(int j=1; j<=k; j++)
            {
                sc(a);
                edges[i].pb(a);
            }
        }
        int mx=-INF,idx=1;

        for(int i=1;i<=n;i++)
        {
            int xx=dfs(i);

            if(xx>mx)
            {
                mx=xx;
                idx=i;
            }
            mmset(visited,0);
        }

        for(int i=1;i<=n;i++)
            edges[i].clear();
        Pr(idx);
    }
    return 0;
}
