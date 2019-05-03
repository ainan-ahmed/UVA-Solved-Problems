#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define MX  2501
vi edges[MX];
bool visited[MX];
int level[MX];
int cnt[MX];
void bfs(int source)
{
    visited[source]=1;
    level[source]=0;
    int len=edges[source].size();
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int u=q.front();
        q.pop();
         int len=edges[u].size();
    for(int i=0;i<len;i++)
    {
        int v=edges[u][i];
        if(!visited[v])
        {
            visited[v]=1;
            level[v]=level[u]+1;
            cnt[level[v]]++;
            q.push(v);
        }
    }
    }
}
int main()
{

    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,a,y;
    sc(n);
    for(int i=0;i<n;i++)
    {
        sc(a);
        for(int j=1;j<=a;j++){
                sc(y);
        edges[i].pb(y);
    }
    }
    int q;
    sc(q);
    for(int i=1;i<=q;i++)
    {
        sc(a);
        if(edges[a].size()==0)
        {
            printf("0\n");
        }
        else
        {
            bfs(a);
            int ans=INT_MIN,ans2;
            for(int i=1;i<=n;i++)
            {

                if(ans<cnt[i])
                {
                    ans=cnt[i];
                    ans2=i;

                }


            }
            printf("%d %d\n",ans,ans2);
            mmset(cnt,0);
            mmset(level,0);
            mmset(visited,0);


        }
    }




    return 0;
}

