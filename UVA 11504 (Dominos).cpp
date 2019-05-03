#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 10000001
vector< int > edges[MX];
int Time =0;
int start[MX];
pair<int,int> finish[MX];
int flag[MX];
stack<int>ans;
int cycle=0;
/*bool comp(pair<int,int> x,pair<int,int> y)
{
    return x.second>y.second;
}*/
void dfs(int source)
{

    if(flag[source]!=0)return;
    int u=source;
   // Time++;
    //start[u]=Time;
    flag[u]=1;

    for(int i=0;i<edges[u].size();i++)
    {
        int v=edges[u][i];

        if(flag[v]==0)
            dfs(v);

    }

   // Time++;
   // finish[u].second=Time;
   // finish[u].first=u;
    flag[u]=2;
    ans.push(u);



}
int main()
{

   // freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
    int t,n,m,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            edges[x].push_back(y);
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(flag[i]==0)

                dfs(i);

        }


    //    sort(finish+1,finish+5,comp);
    memset(flag,0,sizeof(flag));
      while(!ans.empty()){
           if(flag[ans.top()]==0)
           {
            dfs(ans.top());
            c++;


           }
           ans.pop();
      }
      //  cout<<finish[i].first<<" ";
      cout<<c<<endl;
      for(int i=0;i<MX;i++)
        edges[i].clear();
      memset(flag,0,sizeof(flag));
    }
    return 0;
}
