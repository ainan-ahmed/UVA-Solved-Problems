#include <bits/stdc++.h>
#define mkp make_pair
#define pii pair<int,int>
#define MX 101
#define PI acos(-1)
using namespace std;
vector<int>edges[MX];
int level[MX];
bool visited[MX];
bool check[MX];
void bfs(int source)
{
    visited[source]=1;
    level[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int l=edges[u].size();
            for(int i=0;i<l;i++)
            {
                int v=edges[u][i];
                if(!visited[v])
                {
                    visited[v]=1;
                    level[v]=level[u]+1;
                    q.push(v);
                }
            }
    }
}
int main()
{

   //  freopen("input.txt","r",stdin);
     //  freopen("output.txt","w",stdout);
    int x,y,k=1;
    bool flag=0;
    vector<int>val;
    while(scanf("%d%d",&x,&y))
    {

        if(x==0 &&y==0)
        {
                if(flag==1)
                {
                    return 0;
                }
                else
                {
                    long long sum=0;
                    int len=val.size();
                    for(int i=0;i<len;i++)
                    {

                        bfs(val[i]);
                        for(int j=0;j<len;j++)
                        {
                           // cout<<i<<"  "<<level
                            sum+=level[val[j]];
                        }
                        memset(visited,0,sizeof(visited));
                        memset(level,0,sizeof(level));

                    }
                   // cout<<sum<<" "<<len<<endl;
                    double avg=(double)sum/(len*(len-1));
                    printf("Case %d: average length between pages = %.3lf clicks\n",k++,avg);
                    for(int i=1;i<=MX;i++)
                        edges[i].clear();
                        memset(check,0,sizeof(check));
                        val.clear();
                    flag=1;
                    continue;
                }


        }
        if(!check[x])
        {
            val.push_back(x);
            check[x]=1;
        }
        if(!check[y])
        {
            val.push_back(y);
            check[y]=1;
        }
        flag=0;
        edges[x].push_back(y);

    }
        return 0;
}
