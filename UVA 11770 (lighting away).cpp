t#include <bits/stdc++.h>
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
#define MX              10002
vi edges[MX];
bool colour[MX];
stack<int>st;
void dfs(int u)
{
    colour[u]=1;
    int len=edges[u].size();
    for(int i=0; i<len; i++)
    {
        int v=edges[u][i];
        if(!colour[v])
        {
            dfs(v);
        }
    }
    st.push(u);
  //  cout<<u<<endl;

}
int solve(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(!colour[i])
        {
            dfs(i);
        }
    }
    int mark=0;
    mmset(colour,0);
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!colour[u])
        {
           // cout<<u<<endl;
            ++mark;
            dfs(u);
        }
    }
    return mark;
}

int main()
{

    //freopen("input.txt","r",stdin);
   //     freopen("output.txt","w",stdout);
    int n,m,tc,t,x,y ;
    sc(t);
    tcs(tc,t)
    {
        sc2(n,m);
        for(int i=1; i<=m; i++)
        {
            sc2(x,y);
            edges[x].pb(y);
        }
        int mark=solve(n);

        printf("Case %d: %d\n",tc,mark);
        mmset(colour,0);
        for(int i=1;i<=n;i++)
            edges[i].clear();


    }

    return 0;
}
