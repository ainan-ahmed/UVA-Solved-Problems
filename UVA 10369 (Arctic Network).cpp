#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 500
map<double,double>parent;
map<double,bool> flag;
vector<double>ans;
struct edge
{
    double u;
    double v;
    double w;
};
vector < edge > v;
vector<double>edges;
bool comp(edge x,edge y)
{
    if(x.w<y.w)return true;
    else
        return false;
}
double Find(double x)
{
    if(parent[x] == x)return x;
    parent[x]=Find(parent[x]);
    return parent[x];
}
void Union(double a,double b)
{
    if(Find(a)==Find(b))
        printf("They are already friends\n");
    else
    {
       // parent[a]=parent[b];
    }
}
void mst(double n,double s)
{
    sort(v.begin(),v.end(),comp);
    for(double i=1; i<=n; i++)parent[i]=i;
    int c=0,l=v.size();

    for(double i=0; i<l; i++)
    {

        double p=Find(v[i].u);
        double q=Find(v[i].v);
        if(p!=q)
        {
          //  edges.push_back(i);
            parent[p]=q;
            c++;
            //ans += v[i].w;
            ans.push_back(v[i].w);
            if(c==n-1)break;

        }
    }

}
/*double secondBestMst(double n)
{
    double best2=double_MAX;
    double len=edges.size();
    for(double k=0; k<len; k++)
    {
        for(double i=1; i<=n; i++)
        {
            parent[i]=i;
        }
        double s=0,c=0;
        for(double i=0; i<v.size(); i++)
        {
            if(edges[k]==i)continue;
            double p=Find(v[i].u);
            double q=Find(v[i].v);
            if(p!=q)
            {

                parent[p]=q;
                c++;
                s += v[i].w;
                if(c==n-1)
                {
                    if(best2>s)
                        best2=s;
                    break;

                }



            }
        }

    }
    return best2;
}*/
int main()
{

     //freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
    double t,s,p,x,y;
    scanf("%lf",&t);
    vector<pair < double,double > > co_ord;
    while(t--)
    {
        scanf("%lf%lf",&s,&p);


    for(double i=1; i<=p; i++)
    {
        scanf("%lf%lf",&x,&y);
        co_ord.push_back(make_pair(x,y));

    }
        double l=co_ord.size();
        for(double i=0;i<l-1;i++)
        {
            for(double j=i+1;j<l;j++)
            {
                edge get;
                get.u=i+1;
                get.v=j+1;
                get.w=sqrt(((co_ord[j].first-co_ord[i].first)*(co_ord[j].first-co_ord[i].first))+((co_ord[j].second-co_ord[i].second)*(co_ord[j].second-co_ord[i].second)));
                v.push_back(get);
              //  cout<<get.u<<" "<<get.v<<" "<<get.w<<endl;
            }
        }
        mst(p,s);
        printf("%.2lf\n",ans[p-s-1]);
        parent.clear();
        v.clear();
        co_ord.clear();
        ans.clear();

    }
    return 0;
}
