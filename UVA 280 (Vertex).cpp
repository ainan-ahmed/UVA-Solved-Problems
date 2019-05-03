#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 101
vector< int > edges[MX];
int flag[MX];
vector<int>ans;

void dfs(int source)
{

   // if(flag[source]!=0)return;
    int u=source;
    // Time++;
    //start[u]=Time;


    for(int i=0; i<edges[u].size(); i++)
    {
        int v=edges[u][i];

        if(flag[v]==0)
        {
          //  cout<<v<<" ";
            flag[v]=1;
            dfs(v);
        }

    }
   // flag[u]=2;

}
int main()
{

   // freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    int  n,x,y;
    while(cin>>n)
    {
        if(n==0)return 0;
        while(scanf("%d",&x))
        {
            if(x==0)break;

            while(scanf("%d",&y))
            {

                if(y==0)break;
                edges[x].push_back(y);
            }
        }
        int q,c=0;
        scanf("%d",&q);
        while(q--)
        {
            ans.clear();
            memset(flag,0,sizeof(flag));
            scanf("%d",&x);
            dfs(x);
            for(int i=1; i<=n; i++)
            {
                if(flag[i]==0)
                {
                    c++;
                    ans.push_back(i);

                }

            }
            int l=ans.size();
            printf("%d",c);
            for(int i=0; i<ans.size(); i++)
            {
                printf(" %d",ans[i]);
            }
            printf("\n");
            c=0;

        }
        for(int i=0; i<MX; i++)
            edges[i].clear();

    }
    return 0;
}
