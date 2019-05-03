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
#define sc5(a,b,c,d,e)  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define tcs(t)          for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MOD             100000007
#define MX              105
//int fx[]={-1,-1,0,1,1,1,0,-1};
//int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int d[MX][MX];
int cost[MX][MX];
map<string,int>mp;
string s,s1;
void bellman_Ford(int n,int source,int m)
{
    for(int i=1; i<=n; i++){

            d[i][0]=cost[1][i];

    }
    for(int steps=1; steps<=n; steps++)
    {
        for(int i=1; i<=n; i++)
        {
            d[i][steps]=d[i][steps-1];
            for(int j=1;j<=n;j++)
            {

                d[i][steps]=min(d[i][steps],d[j][steps-1]+cost[j][i]);

            }


        }
    }


}

int main()
{

          freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
         int t, n,m, w,q,a;

         sc(t);
         tcs(t)
         {
               mmset(d,INF);
                sc(n);
                 getchar();
                for(int i=1;i<=n;i++)
                {
                   cin>>s;
                    mp[s]=i;
                    cost[i][i]=0;
                    for(int j=i+1;j<=n;j++)
                        cost[i][j]=cost[j][i]=INF;
                }
            sc(m);
            getchar();
        for(int i=1; i<=m; i++)
        {
            cin>>s>>s1>>w;
            int tmp=mp[s],tmp2=mp[s1];
            if(tmp>tmp2)swap(tmp,tmp2);

            cost[tmp][tmp2]=min(cost[tmp][tmp2],w);


        }
        sc(q);
        bellman_Ford(n,1,m);
        printf("Scenario #%d\n",tc);
        while(q--){
                sc(a);
                if(a>n)a=n;
            if(d[n][a]==INF)
                printf("No satisfactory flights\n");
            else
            {
                printf("Total cost of flight(s) is $%d\n",d[n][a]);
            }


        }


        if(tc!=t)printf("\n");
        mp.clear();
         }
    return 0;
}

