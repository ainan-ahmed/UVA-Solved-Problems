#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 100001
map<double,double> parent;
struct edge
{
    double u;
    double v;
    double w;
};
vector < edge > v;
bool comp(edge x,edge y)
{
    if(x.w<y.w)return true;
    else
        return false;
}
double Find(double x)
{
    if(parent[x]==x)return x;
    parent[x]=Find(parent[x]);
    return parent[x];
}
double mst(double n)
{
    sort(v.begin(),v.end(),comp);
    for(double i=1;i<=n;i++)parent[i]=i;
    double c=0,ans=0,l=v.size();
    for(double i=0;i<l;i++)
    {
        double p=Find(v[i].u);
        double q=Find(v[i].v);
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

    freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    int t,n,m,z,k=0;
    double x,y;
    scanf("%d",&t);
    vector < pair <double,double> > pr;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%lf%lf",&x,&y);
           pr.push_back(make_pair(x,y));

        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++){
            edge get;
            get.u=i;
            get.v=j;
            get.w=sqrt(((pr[j].first-pr[i].first)*(pr[j].first-pr[i].first))+((pr[j].second-pr[i].second)*(pr[j].second-pr[i].second)));
            v.push_back(get);
            }
        }

       printf("%.2lf\n",mst(n));
       if(t!=0)
        printf("\n");
        v.clear();
        parent.clear();
        pr.clear();



    }
    return 0;
}
