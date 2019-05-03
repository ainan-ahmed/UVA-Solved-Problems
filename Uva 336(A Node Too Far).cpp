#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 31
//vector<int>edges[MX];
map<int,vector<int> > edges;
//bool visited[MX];
map<int,bool>visited;
//int level[MX];
map<int,int>level;
int bfs(int source,int ttl)
{
    int u,v,c=0;
    queue<int>q;
    if(edges[source].size()==0){
        return 0;
    }
    q.push(source);
    level[source]=0;
    visited[source]=1;
    c++;
    //cout<<source<<" ";
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        int sz=edges[u].size();
        for(int i=0;i<sz;i++)
        {
            if(visited[edges[u][i]]==0)
            {
                int temp=edges[u][i];
                visited[temp]=true;
                level[temp]=level[u]+1;
                if(level[temp]>ttl)break;
               // cout<<temp<<" ";
                c++;

                q.push(temp);
            }
        }

    }
    return c;

}
/*int shortest_path(int n,int ttl)
{
    queue<int>vv;
    vv.push(n);
    int level=0,c=0;
    visited2[n]==1;
    c++;

    while(!vv.empty())
    {
        int u=vv.front();
        if(level[u]>ttl)break;
        vv.pop();
       // cout<<"asd"<<endl;
        for(int i=0;i<edges[u].size();i++)
        {
            int v=edges[u][i];
            if(visited2[v]==0){
                    visited2[v]=1;
                    c++;


            vv.push(v);

        }

    }



    return c;

}*/
int main()
{

 // freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
  int x,y,n;
  set<int>st;
  int tc=0;
  while(scanf("%d",&n)){
        if(n==0)return 0;

    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
        st.insert(x);
        st.insert(y);

    }
    int a;
    while(scanf("%d%d",&x,&y))
    {
            if(x==0 && y==0)break;

            a=st.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++tc,a-bfs(x,y),x,y);

           visited.clear();
           level.clear();

    }

     edges.clear();
    st.clear();

  }

    return 0;
}
