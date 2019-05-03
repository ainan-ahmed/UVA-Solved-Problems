#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 10000001
map<string,int>indegree;
map<string ,int>order;
map < string,vector<string> >edges;
struct data{
string s;
int val;
data(string x,int v)
{
    s=x;
    val=v;
}
};
vector<string>ans;
struct compare_ {
        bool operator()(const data& l,const data&r)
        {
            return l.val>r.val;
        }
};
priority_queue<data,vector<data>,compare_>zero;
bool comp(pair<string,int>x,pair<string,int>y)
{
    return x.second<y.second;

}
void topsort()
{

    while(!zero.empty())
    {
        string x=zero.top().s;
        ans.push_back(x);
        zero.pop();
        int len2=edges[x].size();

        for(int j=0;j<len2;j++)
        {
            string temp = edges[x][j];
          //  cout<<temp<<" "<<indegree[temp]<<endl;
          if(indegree[temp]==-1)
          {
              continue;
          }

                --indegree[temp];
            if(indegree[temp]==0)zero.push(data(temp,order[temp]));

        }

    }

}
int main()
{

   //freopen("input.txt","r",stdin);
   //   freopen("output.txt","w",stdout);
    int n,m,cs=1;
    string s,s1;
    while(scanf("%d",&n)!=EOF){

    for(int i=1;i<=n;i++)
    {
        cin>>s;
        order[s]=i;
        indegree[s]=-1;
    }
        scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        cin>>s>>s1;
        if(indegree[s1]==-1)indegree[s1]=1;
        else
            indegree[s1]++;

        edges[s].push_back(s1);
       // edges[s1].push_back(s);
    }
    vector<pair<string,int> >vx(indegree.begin(),indegree.end());
    sort(vx.begin(),vx.end(),comp);
    int l=vx.size();
    for(int i=0;i<l;i++)
    {

     //   cout<<vx[i].first<<" "<<vx[i].second<<endl;
        if(vx[i].second==-1)
        {

            zero.push(data(vx[i].first,order[vx[i].first]));
        }
       // else
          //  break;
    }


    topsort();
    printf("Case #%d: Dilbert should drink beverages in this order:",cs++);
    for(int i=0;i<ans.size();i++)
        cout<<" "<<ans[i];
    printf(".\n\n");
    edges.clear();
    indegree.clear();
    order.clear();
    ans.clear();
    }
    return 0;
}
