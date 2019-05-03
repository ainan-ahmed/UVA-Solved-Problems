#include <bits/stdc++.h>
using namespace std;
typedef                 long long ll;
typedef                 unsigned long long ull;
#define mkp             make_pair
#define pii             pair<int,int>
#define piii            pair<int,pii>
#define vi              vector<int>
#define PI              acos(-1)
#define all(v)          v.begin(),v.end()
#define sc(a)           scanf("%d",&a)
#define scll(a)         scanf("%I64d",&a)
#define sc2(a,b)        scanf("%d%d",&a,&b)
#define mmset(a,val)    memset(a,val,sizeof(a))
#define scll2(a,b)      scanf("%I64d%I64d",&a,&b)
#define sc3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)    scanf("%d%d%d%d",&a,&b,&c,&d)
#define sc5(a,b,c,d,e)  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)  scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%lld\n",a)
#define pb(a)           push_back(a)
#define tcs(t)          for(int tc=1;tc<=t;tc++)
#define INF             0x3f3f3f3f
#define MOD             100000007
#define MX              1005
int fx[]={-1,-1,0,1,1,1,0,-1};
int fy[]={0,1,1, 1,0,-1,-1,-1};
int Set(int n,int pos){return n=n|(1<<pos);}
int reset(int n,int pos){return n=n& ~ (1<<pos);}
bool check(int n,int pos){return (bool) (n& (1<<pos));}
int d[MX][MX];
int t,row,col,cost,q,x,y,tarx,tary;
char s[MX][MX];
bool valid(int tx,int ty)
{
    if(tx>=0&&tx<row&&ty>=0&&ty<col)return true;
    return false;
}
void bfs_01(int i,int j)
{
    d[i][j]=0;
    deque<pii>dq;
    dq.push_front(mkp(i,j));
    while(!dq.empty())
    {
        pii u=dq.front();
       // cout<<u.first<<" "<<u.second<<endl;
        dq.pop_front();
            if(u.first==tarx-1&&u.second==tary-1)break;
            for(int k=0;k<8;k++){
                  int tx=u.first+fx[k];
                  int ty=u.second+fy[k];

            if(valid(tx,ty))
            {
                if(s[u.first][u.second]-'0'==k&&d[tx][ty]>d[u.first][u.second]){
                        d[tx][ty]=d[u.first][u.second];
                        dq.push_front(mkp(tx,ty));

                }
                else if(s[u.first][u.second]-'0'!=k&&d[tx][ty]>d[u.first][u.second]+1){
                d[tx][ty]=d[u.first][u.second]+1;
                    dq.push_back(mkp(tx,ty));
                }

            }

            }
    }
    Pr(d[tarx-1][tary-1]);
}
int main()
{

          freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout);
                sc2(row,col);
                getchar();
                for(int i=0;i<row;i++){
                    scanf("%s",s[i]);

                }
                    sc(q);
                for(int i=1;i<=q;i++)
                {
                    mmset(d,INF);
                    sc4(x,y,tarx,tary);
                    bfs_01(x-1,y-1);
                }
    return 0;
}

