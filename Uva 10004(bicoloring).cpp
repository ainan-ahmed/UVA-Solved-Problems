#include <bits/stdc++.h>
#define PI acos(-1)
#define pii pair<int,int>
#define mkp make_pair
#define sc(a) scanf("%d",&a)
using namespace std;
#define MX 201
vector<int>edges[MX];
int colour[201];
bool visited[201];
void bfs(int source)
{
    memset(colour,-1,sizeof(colour));
    memset(visited,0,sizeof(visited));
    int u,v;
    queue<int>q;
    q.push(source);
    visited[source]=1;
   colour[source]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0;i<edges[u].size();i++)
        {
            int temp=edges[u][i];
            if(visited[temp]==false&&colour[temp]==-1)
            {
                colour[temp]=1-colour[u];
                visited[temp]=true;
                q.push(temp);
            }
            else if(colour[temp]==colour[u])
            {
                printf("NOT BICOLORABLE.");
                return;

            }
        }

    }
        printf("BICOLORABLE.");
}

int main()
{

    freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
  int x,y,node,edge,a=-1;
  while(1)
  {
      sc(node);
      if(node==0)
        return 0;
      sc(edge);
    for(int i=1;i<=edge;i++)
    {
        cin>>x>>y;
        if(a==-1)a=x;
        edges[x].push_back(y);
        edges[y].push_back(x);

    }
        bfs(a);
        printf("\n");
        for(int i=0;i<=node;i++)
        edges[i].clear();
    a=-1;


  }

    return 0;
}


