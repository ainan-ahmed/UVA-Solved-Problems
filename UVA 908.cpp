#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 1000001
int parent[MX];
struct edge{
    int u;
    int v;
    int w;
};
vector < edge > v;
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
void Union(int a,int b)
{
    if(Find(a)==Find(b))
        printf("They are already friends\n");
    else
    {
        parent[a]=parent[b];
    }
}
int mst(int n)
{
    sort(v.begin(),v.end(),comp);
    for(int i=1;i<=n;i++)parent[i]=i;
    int c=0,ans=0,l=v.size();
    for(int i=0;i<l;i++)
    {
        int p=Find(v[i].u);
        int q=Find(v[i].v);
        if(p!=q){
            parent[p]=q;
            c++;
            ans += v[i].w;
            if(c==n-1)break;

        }
    }
    return ans;
}
int main()
{
    int c=1;
     //freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
   int n,k,x,y,z,m;
   while(cin>>n)
    {
        if(c!=1)printf("\n");
        c++;
    for(int i=1;i<=n-1;i++){
        scanf("%d%d%d",&x,&y,&z);
        edge get;
        get.u=x;
        get.v=y;
        get.w=z;
        v.push_back(get);

    }

    printf("%d\n",mst(n));
    v.clear();
    //memset(parent,0,sizeof(parent));

    scanf("%d",&k);
    vector<edge>vx;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        edge New;
        New.u=x;
        New.v=y;
        New.w=z;
        vx.push_back(New);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        edge get;
        get.u=x;
        get.v=y;
        get.w=z;
        v.push_back(get);
    }
    int l=vx.size();
    for(int i=0;i<l;i++)
    {
        v.push_back(vx[i]);
    }
    printf("%d\n",mst(n));
    v.clear();

   // memset(parent,0,sizeof(parent));


   }
    return 0;
}
