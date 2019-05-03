#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 10001
vector< int > edges[MX];
int flag[MX];
vector<int>ans;
int c=0;
void dfs(int source)
{
    int u=source;


    c++;
    flag[u]=1;
    for(int i=0;i<edges[u].size();i++)
    {
        int v=edges[u][i];
        if(flag[v]==0)
        {
            dfs(v);
        }
    }
}
int main()
{

   // freopen("input.txt","r",stdin);
  //   freopen("output.txt","w",stdout);
    int t,n,m,l,x,y;
    scanf("%d",&t);
    while(t--)
    {
        memset(flag,0,sizeof(flag));
            c=0;
            for(int i=0;i<MX;i++)
            edges[i].clear();
        scanf("%d%d%d",&n,&m,&l);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            edges[x].push_back(y);

        }
        for(int i=1;i<=l;i++)
        {

            scanf("%d",&x);
            if(flag[x]==0)
            dfs(x);


        }
        printf("%d\n",c);



    }
    return 0;
}
