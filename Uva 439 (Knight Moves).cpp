#include <bits/stdc++.h>
#define PI acos(-1)
#define pii pair<int,int>
using namespace std;
#define MX 100000
int fx[]={2,2,-2,-2,1,-1,1,-1};
int fy[]={-1,1,-1,1,2,2,-2,-2};
int cell[100][100];
int d[100][100],visited[100][100];
int row=8,col=8;
int bfs(int sx,int sy,int xxx,int yyy)
{
    int tx,ty;
    visited[sx][sy]=1;
    d[sx][sy]=0;
    queue<pii>q;
    q.push(pii(sx,sy));

    while(!q.empty())
    {
        pii u=q.front();
        q.pop();
        for(int k=0;k<8;k++){
             tx=u.first+fx[k];
             ty=u.second+fy[k];

        if(tx>0 && tx<=row and ty>0 &&  ty<=col &&  cell[tx][ty]!=-1 &&  visited[tx][ty]==0)
			{
				visited[tx][ty]=1;
				d[tx][ty]=d[u.first][u.second]+1;
				//cout<<tx<<" "<<ty<<" "<<d[tx][ty]<<endl;
				if(tx==xxx&&ty==yyy){
                    return d[tx][ty];
				}
				q.push(pii(tx,ty));
			}
        }
    }
    return 5;
}
int main()
{

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
 int x,y,x1,y1;
  string s,s1;
    while(cin>>s>>s1)
    {
            memset(visited,0,sizeof(visited));
            memset(d,0,sizeof(d));


        x=s[0]-'a'+1;
        y=s[1]-'0';
        x1=s1[0]-'a'+1;
        y1=s1[1]-'0';
       // cout<<x<<" "<<y<<" "<<x1<<" "<<y1<<endl;
        if(x==x1&&y==y1){
            cout<<"To get from "<<s<<" to "<<s1<<" takes 0 knight moves."<<endl;
            continue;
        }
        int temp=bfs(x,y,x1,y1);
        cout<<"To get from "<<s<<" to "<<s1<<" takes "<<temp<<" knight moves."<<endl;

    }

    return 0;
}
