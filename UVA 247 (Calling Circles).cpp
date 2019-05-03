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
#define MX              27
map<string,int>store;
vi edges[MX];
vi rev_edges[MX];
vi component[MX];
string ara[MX];
stack<int>st;
bool colour[MX],visited[MX];
void dfs(int u)
{
    colour[u]=1;
    int len=edges[u].size();
    for(int i=0;i<len;i++)
    {
        int v=edges[u][i];
        if(!colour[v])
        {
            dfs(v);
        }
    }
    st.push(u);

}
void dfs2(int u,int mark)
{
    visited[u]=1;
    component[mark].pb(u);
    int len=rev_edges[u].size();
    for(int i=0;i<len;i++)
    {
        int v=rev_edges[u][i];
        if(!visited[v])
        {

            dfs2(v,mark);
        }
    }
}
int SCC(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(!colour[i])
        {
            dfs(i);
        }
    }
    int mark=0;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!visited[u])
        {
            ++mark;
            dfs2(u,mark);
        }
    }
    return mark;
}
void CLR()
{
    mmset(visited,0);
    mmset(colour,0);
    for(int i=1;i<=MX;i++){
        edges[i].clear();
        rev_edges[i].clear();
        component[i].clear();
       // ara[i]="\0";
    }
  // ara.clear();
    store.clear();

}
int main()
{

   // freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    int n,m,tc=0;
    string s1,s2;
    while(sc2(n,m)&&(n!=0||m!=0))
    {
        if(tc!=0)printf("\n");
        getchar();
        int idx=0;
        for(int i=1;i<=m;i++)
        {
            cin>>s1>>s2;
            int tmp1=store[s1];
            int tmp2=store[s2];
            if(tmp1==0){
                tmp1=++idx;
                store[s1]=tmp1;
                ara[tmp1]=s1;
            }
            if(tmp2==0){
                tmp2=++idx;
                store[s2]=tmp2;
                ara[tmp2]=s2;
            }
            edges[tmp1].pb(tmp2);
            rev_edges[tmp2].pb(tmp1);
        }
        int mark=SCC(n);
        //cout<<mark<<endl;
        printf("Calling circles for data set %d:\n",++tc);
        for(int i=1;i<=mark;i++)
        {
            int len=component[i].size();
            for(int j=0;j<len;j++)
            {
                printf("%s",ara[component[i][j]].c_str());
                if(j!=len-1)printf(", ");
            }
            printf("\n");
        }

        CLR();
    }

    return 0;
}
