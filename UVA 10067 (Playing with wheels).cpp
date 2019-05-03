#include <bits/stdc++.h>
#define mkp make_pair
#define pii pair<int,int>
#define MX 10002
#define PI acos(-1)
#define sc(a) scanf("%d",&a)
using namespace std;
map<string,int> visited;
map<string,int> level;
int f[8][4]={{-1,0,0,0},{1,0,0,0},{0,1,0,0},{0,-1,0,0},{0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1}};
int main()
{

      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);

    int a,t;
    string s,s1,u,temp;
    sc(t);
    while(t--)
    {
    for(int i=1; i<=4; i++)
    {
        sc(a);
        s+=(char)a+'0';

    }
    for(int i=1; i<=4; i++)
    {
        sc(a);
        s1+=(char)a+'0';

    }
    int block;
    sc(block);
    while(block--)
    {
        for(int i=1; i<=4; i++)
        {
            sc(a);
            temp+=(char)a+'0';

        }
        visited[temp]=1;
        temp.clear();
    }
    if(s==s1)
    {
        printf("0\n");
        s.clear(),s1.clear();
         visited.clear();
        continue;
    }
    queue<string>q;
    bool flag=0;
    visited[s]=1;
    q.push(s);
    while(!q.empty())
    {
        if(flag==1)
            break;
        u=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
         //   cout<<u<<" "<<i+1<<endl;

            if(flag==1)
                break;
            temp=u;
            for(int j=0;j<4;j++)
            {
                if(temp[j]=='0'&&f[i][j]==-1)
                {
                 //   cout<<"9xxxxxxxxx"<<endl;
                    temp[j]='9';
                }
                else if(temp[j]=='9'&& f[i][j]== 1 )
                {

                   // cout<<"0xxxxxxxxxx"<<endl;
                    temp[j]='0';
                }
                else
                    temp[j]+=f[i][j];
            }
           //  cout<<u<<"\t"<<temp<<" level::-- "<<endl;
            if(!visited[temp])
            {
                visited[temp]=1;
                level[temp]=level[u]+1;

                if(temp==s1)
                {
                    printf("%d\n",level[temp]);
                    flag=1;

                }

                q.push(temp);
            }
        }
    }
    if(!flag)
        printf("-1\n");
        visited.clear();
        level.clear();
        s.clear(),s1.clear();
        temp.clear();
    }
    return 0;
}
