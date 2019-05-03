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
#define MX              2005
int value[MX];
int li[MX],ld[MX];
int n;
int LIS(int u)
{
    if(li[u]!=-1)return li[u];
    int mx=0;
    for(int v=u+1;v<=n;v++)
    {
        if(value[v]>value[u]){
        int tmp=LIS(v);
        if(tmp>mx)
        {
            mx=tmp;
        }

        }
    }
    li[u]=1+mx;
    return li[u];
}
int LDS(int u)
{
    if(ld[u]!=-1)return ld[u];
    int mx=0;
    for(int v=u+1;v<=n;v++)
    {
        if(value[v]<value[u]){
        int tmp=LDS(v);
        if(tmp>mx)
        {
            mx=tmp;
        }

        }
    }
    ld[u]=1+mx;
    return ld[u];
}
int main()
{

     freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);

    int t;
    sc(t);
    while(t--)
    {
        sc(n);
        for(int i=1; i<=n; i++)
        {
            sc(value[i]);
        }

        mmset(li,-1);
        mmset(ld,-1);
        for(int i=1;i<=n;i++)
        {
            LIS(i);
            LDS(i);
        }

        int mx=0;
        for(int i=1;i<=n;i++)
        {
            if(li[i]+ld[i]-1>mx)
            {
                mx=li[i]+ld[i]-1;

            }

        }
        Pr(mx);


    }



    return 0;
}
