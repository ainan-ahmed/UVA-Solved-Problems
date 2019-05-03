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
#define MX              100002
int value[MX];
int length[MX];
int li[MX],ld[MX];

int n;
int LIS(int u)
{
    if(li[u]!=-1)return li[u];
    int mx=0;
    for(int v=u+1;v<=n;v++)
    {
        if(value[v]>value[u]){

        int tmp=LIS(v)+length[u];
        if(tmp>mx)
        {
            mx=tmp;

        }

        }
    }
    li[u]=max(mx,length[u]);
    return li[u];
}
int LDS(int u)
{
    if(ld[u]!=-1)return ld[u];
    int mx=0;
    for(int v=u+1;v<=n;v++)
    {
        if(value[v]<value[u]){
        int tmp=LDS(v)+length[u];
        if(tmp>mx)
        {
            mx=tmp;

        }

        }
    }
    ld[u]= max(mx,length[u]);
    return ld[u];
}

int main()
{

    // freopen("input.txt","r",stdin);
    //   freopen("output.txt","w",stdout);

    int t,tc ;
    sc(t);
    tcs(tc,t)
    {
        sc(n);
        for(int i=1; i<=n; i++)
        {
            sc(value[i]);
        }
        for(int i=1; i<=n; i++)
        {
            sc(length[i]);
        }
        mmset(li,-1);
        mmset(ld,-1);
        int mx_i=0,mx_d=0;
        for(int i=1;i<=n;i++)
        {
           mx_i=max(mx_i, LIS(i));
             mx_d=max(LDS(i),mx_d);
        }

        printf("Case %d. ", tc);
        if(mx_i>=mx_d)
            printf("Increasing (%d). Decreasing (%d).\n",mx_i,mx_d);
        else
            printf("Decreasing (%d). Increasing (%d).\n",mx_d,mx_i);




    }



    return 0;
}
