#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 10000001
vector<int>edges[27];
bool visited[27];
void dfs(int n)
{
    visited[n]=1;
    int l=edges[n].size();
    for(int i=0;i<l;i++)
    {
        int v=edges[n][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }

}
int main()
{

   // freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
    char mx,ch1,ch2;
    string s;
    int t,x,y,b;
    scanf("%d",&t);
  //  printf("\n");
    while(t--)
    {
        memset(visited,0,sizeof(visited));
        for(int i=0;i<26;i++)
            edges[i].clear();
        cin>>mx;
        b=mx-65;
       // cout<<b<<endl;
       getchar();
        while(getline(cin,s)&&s!="")
        {

            ch1=s[0];
            ch2=s[1];

            x=ch1-65;
            y=ch2-65;
            //cout<<"\n"<<x<<" "<<y<<endl;
            edges[x].push_back(y);
            edges[y].push_back(x);


        }
        int cnt=0;
        for(int i=0;i<=b;i++)
        {
            if(!visited[i])
            {
                dfs(i);
                cnt++;
            }
        }
        printf("%d\n",cnt);

        if(t!=0)printf("\n");

    }
    return 0;
}
