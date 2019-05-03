#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 10001
int parent[MX];
struct edge
{
    int u;
    int v;
    int w;
};
vector < edge > v;
vector<int>edges;
int secondmst[202],xx=0;
bool flag1,flag2;
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
int mst(int n)
{
    sort(v.begin(),v.end(),comp);
    for(int i=1; i<=n; i++)parent[i]=i;
    int c=0,ans=0,l=v.size();
    if(n==1&&l==0)
        flag1=true;
    for(int i=0; i<l; i++)
    {
        int p=Find(v[i].u);
        int q=Find(v[i].v);

        if(p!=q)
        {
            edges.push_back(i);
            parent[p]=q;
            ++c;
            ans += v[i].w;

            if(c==n-1)
            {
                flag1=true;
                break;

            }
        }
    }

    return ans;
}
int secondBestMst(int n)
{
    int best2=INT_MAX,c=0;
    int len=edges.size();
    for(int k=0; k<len; k++)
    {
        for(int i=1; i<=n; i++)
        {
            parent[i]=i;
        }
        int s=0;
        c=0;
        for(int i=0; i<v.size(); i++)
        {
            if(edges[k]==i)continue;
            int p=Find(v[i].u);
            int q=Find(v[i].v);
            if(p!=q)
            {

                parent[p]=q;
                c++;
                s += v[i].w;
                if(c==n-1)
                {
                    if(best2>s)
                    {
                        best2=s;
                        secondmst[xx++]=best2;
                    }
                    flag2=true;
                    break;

                }



            }

        }

    }

    return best2;
}
int main()
{

   //  freopen("input.txt","r",stdin);
   //  freopen("output.txt","w",stdout);
    int t,n,m,x,y,z,k=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
           // if(x>y)swap(x,y);
            edge get;
            get.u=x;
            get.v=y;
            get.w=z;
            v.push_back(get);

        }





        int ans=mst(n);
        int ans2=secondBestMst(n);

        if(n==1)flag1=true;
        // cout<<ans<<"   "<<ans2<<endl;
        if(flag1&&!flag2)
            printf("Case #%d : No second way\n",++k);
        else if(!flag1)
            printf("Case #%d : No way\n",++k);
        else
        {
            sort(secondmst,secondmst+xx);
            printf("Case #%d : %d\n",++k,secondmst[0]);


        }

        flag1=false,flag2=false;
        memset(secondmst,0,sizeof(secondmst));
        xx=0;
        v.clear();
        edges.clear();



    }



    return 0;
}
