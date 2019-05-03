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
string xx[MX],s,s1;
map<string,int>mp;
vi edges[MX];
bool visited[MX],articulation_point[MX];
int d[MX],low[MX],parent[MX],t,cam;
void art_point(int u,int prev)
{
    t++;
    low[u]=d[u]=t;
    visited[u]=1;
        int children=0;
    int len=edges[u].size();
    for(int i=0;i<len;i++)
    {
        int v=edges[u][i];
         // if(v==prev)continue;
        if(visited[v]&&v!=prev)
        {
            low[u]=min(low[u],d[v]);
        }
        else if(!visited[v])
        {
            parent[v]=u;
            art_point(v,u);
            low[u]=min(low[u],low[v]);
            children++;
            if((d[u]<=low[v]&&prev!=-1)||(children>1&&prev==-1))
            {
                articulation_point[u]=1;

            }


        }
    }
}
void CLR()
{
        mmset(visited,0);
        mmset(articulation_point,0);
        for(int i=0;i<=MX;i++)
            edges[i].clear();
            mp.clear();
            t=0;

}
int main()
{
          freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
        int n,x,y,m,tc=0;
        while(sc(n)&&n!=0){
                CLR();
                if(tc!=0)
                printf("\n");

                for(int i=1;i<=n;i++)
                {
                    cin>>s;

                    mp[s]=i;
                    xx[i]=s;
                }
                sc(m);

        for(int i=1;i<=m;i++)
        {
           cin>>s>>s1;

            int tmp=mp[s];
            int tmp2=mp[s1];
            edges[tmp].pb(tmp2);
            edges[tmp2].pb(tmp);
        }


        for(int i=1;i<=n;i++){
                if(!visited[i])
                    art_point(i,-1);
        }

        vector<string>v;
        for(int i=1;i<=n;i++)
        {
                if(articulation_point[i])
                {
                    v.pb(xx[i]);
                }
        }
        sort(all(v));
        int len=v.size();
        printf("City map #%d: %d camera(s) found\n",++tc,len);
        for(int i=0;i<len;i++)
        {
            cout<<v[i]<<endl;
        }



        }
    return 0;
}

