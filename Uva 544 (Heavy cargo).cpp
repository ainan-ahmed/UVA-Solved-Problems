#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 100001
map<string,string> parent;
struct edge
{
    string u;
    string v;
    int w;
};
vector < edge > v;
bool comp(edge x,edge y)
{
    if(x.w>y.w)return true;
    else
        return false;
}
string Find(string x)
{
    if(parent[x]==x)return x;
    parent[x]=Find(parent[x]);
    return parent[x];
}
int mst(int n,string x,string y)
{

    int c=0,ans=INT_MAX,l=v.size();
    for(int i=0; i<l; i++)
    {
        string p=Find(v[i].u);
        string q=Find(v[i].v);

        if(p!=q)
        {
            parent[p]=q;
            c++;

                if(ans>v[i].w)
                {

                    ans=v[i].w;

                }
                if(Find(x)==Find(y))
                    break;

        }
            if(c==n-1)break;

        }

    return ans;
}
int main()
{

   // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    int n,m,z,k=0;
    string x,y;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)return 0;
        for(int i=1; i<=m; i++)
        {
            cin>>x>>y>>z;
            if(parent[x].empty())parent[x]=x;
            if(parent[y].empty())parent[y]=y;
            edge get;
            get.u=x;
            get.v=y;
            get.w=z;
            v.push_back(get);

        }
        cin>>x>>y;
        sort(v.begin(),v.end(),comp);

        int ans=mst(n,x,y);
        printf("Scenario #%d\n%d tons\n\n",++k,ans);
        v.clear();
        parent.clear();


    }
    return 0;
}
