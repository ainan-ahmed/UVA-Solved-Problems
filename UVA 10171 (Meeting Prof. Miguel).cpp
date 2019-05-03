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
#define MX  27
int cost1[MX][MX];
int cost2[MX][MX];
char c;
void floyd_warshall(int n)
{

    for(int k=1; k<=MX; k++)
    {
        for(int i=1; i<=MX; i++)
        {
            for(int j=1; j<=MX; j++)
            {
                if(cost1[i][j]>cost1[i][k]+cost1[k][j])
                {
                    cost1[i][j]=cost1[i][k]+cost1[k][j];
                }
                if(cost2[i][j]>cost2[i][k]+cost2[k][j])
                {
                    cost2[i][j]=cost2[i][k]+cost2[k][j];
                }

            }
        }
    }
}
int calc(int x,int y,int n)
{
    int ans=INF;
    for(int i=1;i<=MX;i++)
    {
      if(cost1[x][i]+cost2[y][i]<ans)
        {

            ans=cost1[x][i]+cost2[y][i];
            c=i+'A'-1;
        }
    }

    return ans;
}
int main()
{

     //   freopen("input.txt","r",stdin);
       //    freopen("output.txt","w",stdout);
    int n,w,temp1,temp2;
    char c1,c2,c3,c4;
    while(sc(n)&&n!=0)
    {

        for(int i=1; i<=MX; i++)
        {
            for(int j=1; j<=MX; j++)
            {
                if(i==j)
                {
                    cost1[i][j]=0;
                    cost2[i][j]=0;
                }
                else{
                cost1[i][j]=INF;
                cost2[i][j]=INF;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            getchar();
            scanf("%c %c %c %c %d",&c1,&c2,&c3,&c4,&w);
            temp1=c3-'A'+1 ;
            temp2=c4-'A'+1 ;
           // cout<<temp1<<" "<<temp2<<endl;
           if(temp1==temp2)continue;
            if(c1=='Y')
            {
                if(c2=='U')
                {

                    cost1[temp1][temp2]=w;
                }
                else
                {


                    cost1[temp1][temp2]=w;
                    cost1[temp2][temp1]=w;
                }
            }
            else
            {
                if(c2=='U')
                {
                    cost2[temp1][temp2]=w;
                }
                else
                {
                    cost2[temp1][temp2]=w;
                    cost2[temp2][temp1]=w;
                }
            }
        }
        floyd_warshall(n);






        getchar();
        scanf("%c %c",&c1,&c2);
        temp1=c1-'A'+1;
        temp2=c2-'A'+1;

      //  cout<<temp1<<" "<<temp2<<endl;
       int ans= calc(temp1,temp2,n);
       if(ans==INF)
       {
           printf("You will never meet.\n");
       }
       else
       {
           printf("%d",ans,c);
           for(int i=1;i<=MX;i++)
           {
               if(cost1[temp1][i]+cost2[temp2][i]==ans)
                printf(" %c",i+'A'-1);

           }
           printf("\n");

       }
    }
    return 0;
}
