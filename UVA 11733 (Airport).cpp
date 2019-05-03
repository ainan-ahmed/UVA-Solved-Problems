#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 1000001
int parent[MX];
bool flag[MX];
struct edge
{
    int u;
    int v;
    int w;
};
vector < edge > v;
vector<int>edges;
map<int,int>mp;
int cnt=0;
bool comp(edge x,edge y)
{
    if(x.w<y.w)return true;
    else
        return false;
}
int Find(int x)
{
    if(parent[x]==x)return x;
    parent[x]=Find(parent[x]);
    return parent[x];
}
int mst(int n,int d)
{
    sort(v.begin(),v.end(),comp);
   //for(int i=0;i<v.size();i++)
     //   cout<<v[i].u<<" "<<v[i].v<<" "<<v[i].w<<endl;
    for(int i=1; i<=n; i++)parent[i]=i;
    int c=0,ans=0,l=v.size();
    for(int i=0; i<l; i++)
    {
        if(v[i].w>=d)break;
        int p=Find(v[i].u);
        int q=Find(v[i].v);

        if(p!=q)
        {


           edges.push_back(i);


                parent[p]=q;

            ++c;
            ans += v[i].w;

            if(c==n-1)break;

        }
    }
    return ans;
}
int main()
{

   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,n,m,d,x,y,z,k=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&n,&m,&d);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(x>y)swap(x,y);
            edge get;
            get.u=x;
            get.v=y;
            get.w=z;
            v.push_back(get);

        }
        int ans=mst(n,d);


      for(int i=1;i<=n;i++)
      {
          //cout<<parent[i]<<" "<<i<<endl;
          if(parent[i]==i)cnt++;
      }
        printf("Case #%d: %d %d\n",++k,ans+(d*cnt),cnt);
        cnt=0;
        memset(flag,0,sizeof(flag));
        v.clear();
        edges.clear();
        mp.clear();


    }



    return 0;
}
