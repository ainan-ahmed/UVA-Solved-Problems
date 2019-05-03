#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define sc4(a,b,c,d)      scanf("%d%d%d%d",&a,&b,&c,&d)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)    scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Pr(a)           printf("%d\n",a)
#define Prll(a)         printf("%I64d\n",a)
#define pb(a)           push_back(a)
#define tcs(tc,t)       for(int tc=1;tc<=t;tc++)
#define INF 0x3f3f3f3f
#define MX  10000
int cost[MX][MX];
int path[MX][MX];
int tax[MX];
void floyd_warshall(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(cost[i][j]==-1)
                cost[i][j]=INF;
           // else if(cost[i][j]!=-1&&i!=j)
              //  cost[i][j]+=tax[j];
            path[i][j]=j;
        }
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
             //if(cost[i][j]==INF)
                    //cost[i][j]= cost[i][k]+cost[k][j];
                if(cost[i][j]>cost[i][k]+cost[k][j]+tax[k])
                {

                   // else
                        cost[i][j]= cost[i][k]+cost[k][j]+tax[k] ;
                    path[i][j]=path[i][k];
                }
            }
        }
    }
}
void print(int i,int j)
{
    int temp=i;

    printf("From %d to %d :\nPath: %d",i,j,i);
    if(temp==j){
        printf("\nTotal cost : 0\n");
        return  ;
    }
   // ll taxes=0;
    while(i!=j)
    {  // if(i!=temp)
        // taxes+=tax[i];
        i=path[i][j];

        printf("-->%d",i);

    }

    printf("\nTotal cost : %d\n",cost[temp][j]);
}
int main()
{

  //    freopen("input.txt","r",stdin);
   //     freopen("output.txt","w",stdout);
    int t,tmp,xx=1;
    sc(t);
    getchar();
        getchar();

    while(t--)
    {

        xx=1;
        string s;
        getline(cin,s);
        stringstream ss(s);
        while(ss>>tmp)
        {
            cost[1][xx]=tmp;
            //cout<<tmp<<endl;
            xx++;
        }
        --xx;

        for(int i=2; i<=xx; i++)
        {
            for(int j=1; j<=xx; j++)
            {
                sc(cost[i][j]);
            }
        }
        for(int i=1; i<=xx; i++)
            sc(tax[i]);
        floyd_warshall(xx);
       /* for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
                cout<<cost[i][j]<<" ";
            cout<<endl;
        }*/
    getchar();
            int x,y,cnt=0;
            char c,c1;
            getline(cin,s);
            while(1){


            if(s.length()==0){
                            if(t!=0)
                            printf("\n");
                             break;
                    }
                    else if(cnt!=0)
                        printf("\n");

                cnt++;

            stringstream sss(s);
            sss>>x>>y;

            print(x,y);

            getline(cin,s);




        }
    }
    return 0;
}
