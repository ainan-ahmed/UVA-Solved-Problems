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
#define tcs(tc,t)       for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MX              28
char c,d;
vi edges[MX];
bool visited[MX];
vi ans;
int cnt=0;
bool valid(int u)
{
    int len=edges[u].size();
    for(int i=0;i<len;i++)
    {
        int v=edges[u][i];
        if(!visited[v])
            return false;

    }
    return true;
}
void dfs(int source,int sz)
{
    if(ans.size()==sz)
    {
        cnt++;
        for(int i=0;i<sz;i++)
        {
           c=ans[i]+'A'-1;
           if(i!=0)
            printf(" ");
           printf("%c",c);

        }
       printf("\n");
        return;
    }

    for(int i=0;i<sz;i++)
    {
        int v=edges[0][i];
        if(!visited[v]&&valid(v))
        {
            visited[v]=1;
            ans.pb(v);
            dfs(v,sz);
            visited[v]=0;
            ans.pop_back();

        }
    }


}
int main()
{

     //   freopen("input.txt","r",stdin);
      //  freopen("output.txt","w",stdout);
    string s,s1;
    bool flag=0;
    int t;
    sc(t);
    getchar();
    while(t--)
    {
        getchar();
        getline(cin,s);
        int idx=0;

       // getchar();
       sort(all(s));
        stringstream ss(s);
        while(ss>>c)
        {
            int temp1=c-'A'+1;
            edges[0].pb(temp1);

        }

        getline(cin,s1);
        int len=s1.length();
        idx=edges[0].size();
        for(int i=0;i<len;i+=4)
        {
            int temp1=s1[i]-'A'+1;
            int temp2=s1[i+2]-'A'+1;
         //   cout<<temp1<<" "<<temp2<<endl;
            edges[temp2].pb(temp1);
        }
       // cout<<idx<<endl;
       if(flag)
        printf("\n");
       // cout<<idx<<endl;
        dfs(0,idx);
        if(cnt==0)
        {
            printf("NO\n");
        }
      //  mmset(visited,0);
        for(int i=0;i<=28;i++)
            edges[i].clear();
       flag=true;
       cnt=0;


    }

    return 0;
}
