#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 101
int indegree[MX];
vector < int >edges[MX];
vector<int> zero;
vector<int>ans;
void topsort()
{

    for(int i=0;i<zero.size();i++)
    {
        int x=zero[i];
        ans.push_back(x);
        int len2=edges[x].size();
        for(int j=0;j<len2;j++)
        {
            int temp = edges[x][j];
           // cout<<temp<<" "<<indegree[temp]<<endl;
                --indegree[temp];
                if(indegree[temp]==0)zero.push_back(temp);

        }

    }

}
int main()
{

   // freopen("input.txt","r",stdin);
   //   freopen("output.txt","w",stdout);
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)return 0;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);

        indegree[y]++;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

  //  sort(indegree+1,indegree+n+1);
    for(int i=1;i<=n;i++)
    {
          //  cout<<indegree[i]<<" ";
        if(indegree[i]==0)
        {
            zero.push_back(i);
        }

    }


    topsort();
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)
        cout<<" "<<ans[i];
    cout<<endl;
    for(int i=1;i<n;i++)
    edges[i].clear();
    zero.clear();
    ans.clear();
    memset(indegree,0,sizeof(indegree));
    }
    return 0;
}
