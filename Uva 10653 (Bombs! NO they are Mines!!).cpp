#include <bits/stdc++.h>
#define PI acos(-1)
#define pii pair<int,int>
using namespace std;
#define MX 100000
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int cell[1000][1000];
int d[1000][1000],visited[1000][1000];
int bfs(int sx,int sy,int row,int col,int xxx,int yyy)
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
        for(int k=0;k<4;k++){
             tx=u.first+fx[k];
             ty=u.second+fy[k];

        if(tx>=0 && tx<row && ty>=0 &&  ty<col &&  cell[tx][ty]!=-1 &&  visited[tx][ty]==0)
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

    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int row,col,r,x,y,bomb,x1,x2,y1,y2;
    while(1)
    {
        scanf("%d%d",&row,&col);
        if(row==0&&col==0)return 0;
            memset(visited,0,sizeof(visited));
            memset(d,0,sizeof(d));
            memset(cell,0,sizeof(cell));
            scanf("%d",&r);
            while(r--){
               scanf("%d%d",&x,&bomb);
               while(bomb--)
               {
                   scanf("%d",&y);
                   cell[x][y]=-1;

               }
            }
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            cout<<bfs(x1,y1,row,col,x2,y2)<<endl;

    }

    return 0;
}
