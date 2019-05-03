#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 21
vector<int>edges[MX];
bool visited[MX];
//int parent[MX];
int level[MX];
int bfs(int source,int target)
{
    int u,v;
    queue<int>q;
    for (int i = 1;i <= 20;i++)visited[i] = 0;
    q.push(source);
    level[source]=0;
    visited[source]=1;
    //parent[source]=source;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        int l=edges[u].size();
        for(int i=0;i<l;i++)
        {
            if(visited[edges[u][i]]==0)
            {
                int temp=edges[u][i];
                visited[temp]=true;
                level[temp]=level[u]+1;
                if(temp==target)return level[temp];
                //parent[temp]=u;
                q.push(temp);
            }
        }

    }
    return 200;
}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  int x,y,a,n,k=1;
  while(cin>>a){
    for(int i=1;i<=19;i++)
    {
        if(i!=1)
        scanf("%d",&a);
        while(a--){
                scanf("%d",&x);
        edges[x].push_back(i);
        edges[i].push_back(x);
        }
    }
        scanf("%d",&n);
        printf("Test Set #%d\n",k++);
        while(n--)
        {
            int ans;
            scanf("%d%d",&x,&y);
            if(x<y)ans=bfs(y,x);
            else
                ans=bfs(x,y);
            if(x<10&&y<10)
            printf(" %d to  %d: %d\n",x,y,ans);
            else if(x<10)
                printf(" %d to %d: %d\n",x,y,ans);
                else if(y<10)
                printf("%d to  %d: %d\n",x,y,ans);
                else
                printf("%d to %d: %d\n",x,y,ans);

            memset(visited,0,sizeof(visited));
            memset(level,0,sizeof(level));
        }

        printf("\n");
        for(int i=1;i<=20;i++)
        edges[i].clear();



    }







    return 0;
}
