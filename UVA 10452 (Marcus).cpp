#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
#define MX 10000001
vector< string >ch;
vector<string>ans;
string x="IEHOVA#";
int pos=0;
int t,row,col;
void dfs(int i ,int j)
{

    if(j>0&&ch[i][j-1]==x[pos])
    {
        ans.push_back("left");
        pos++;
        dfs(i,j-1);
        return;
    }
    if(j<col-1&&ch[i][j+1]==x[pos])
    {
        ans.push_back("right");
        pos++;
        dfs(i,j+1);
        return;
    }
    if(i>0){
    ans.push_back("forth");
    pos++;
    dfs(i-1,j);
    return;
    }
}
int main()
{

  //  freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);

    string s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&row,&col);
        for(int i=1;i<=row;i++)
        {
            cin>>s;
            ch.push_back(s);
        }
        bool flag=true;

           for(int j=0;j<col;j++)
           {
               if(ch[row-1][j]=='@'){
                dfs(row-1,j);
              break;
               }
           }
        int l=ans.size();
       for(int i=0;i<l-1;i++)
       {
          cout<<ans[i]<<" ";
       }
       cout<<ans[l-1]<<endl;

       ans.clear();
       ch.clear();
       pos=0;
    }
    return 0;
}
